import { Injectable } from "@nestjs/common";
import { UserRepository } from "../user/user.repository";
import { RoomRepository } from "./room.repository";
import { CreateRoomDto } from "../dto/create-room.dto";
import { RoomStatus } from "./room-status.enum";
import { Server, Socket } from "socket.io";
import { User } from "../user/user.entity";
import { GetUserDto } from "../dto/get-user.dto";
import { UserService } from "../user/user.service";

@Injectable()
export class RoomService {
    // userId, rooms[]
    private roomList = new Map<number, string[]>();
    // <roomname, username[]> => 이건 어쩔 수 없다... 아니면 이것도 roomId로 바꿔?
    private banList = new Map<string, string[]>();

    constructor(
        private roomRepository: RoomRepository,
        private userRepository: UserRepository,
    ) {}

    async getAllRooms() {
        return this.roomList;
    }

    async createRoom(createRoomDto: CreateRoomDto, res) {
        /* DB 저장 */
        try {
            this.banList.set(createRoomDto.chennelName, null);
            const roomStatus = createRoomDto.password === "" ? RoomStatus.PUBLIC : RoomStatus.PRIVATE;
            const user = await this.userRepository.findOneBy({ id: createRoomDto.userId });
            const room = this.roomRepository.create({
                name: createRoomDto.chennelName,
                password: createRoomDto.password,
                status: roomStatus,
                channelOwner:  user,
                Administrator: user,
            });
            const result = await this.roomRepository.save(room);
            await this.userRepository.updateJoinedRoom(user.id, result.id);
            res.header().status(200).send();
        } catch (e) {
            console.log(e);
            res.header().status(555).send();
        }
    }

    async enterRoom(userId: number, roomname: string, client: Socket) {
        const user = await this.userRepository.findOneBy({ id: userId });
        const room = await this.roomRepository.findOneBy({ name: roomname });
        if (!room.members.includes(user)) {
            await this.userRepository.updateJoinedRoom(userId, room.id);
        }
        client.to(roomname).emit('getmessage', {
            type: 'not',
            roomname: roomname,
            userid: userId,
            username: user.username,
            avatar: null,
            msg: `${user.username}님이 ${roomname}에 입장하셨습니다.`
        })
    }

    async ChennelList(res): Promise<void> {
        try {
            // this.roomRepository.createQuery
            const rooms = await this.roomRepository.find();
            res.header().status(200).send(rooms);
        } catch {
            res.header().status(531).send();
        }
    }

    async inviteUser(userId, roomId, res) {
        try {
            const room = await this.roomRepository.findOneBy({ id: roomId });
            await this.userRepository.update(userId, { joinedRoom: room });
            res.sendStatus(200);
        } catch {
            res.sendStatus(500);
        }
    }

    async exitRoom(userId, roomName, client: Socket) {
        // 그냥 null로 바꿨을 때 postman에서 어떻게 뜨는지,,,?
        const user = await this.userRepository.findOneBy({ id: userId });
        const username = user.username;
        await this.userRepository.update(user.id, { joinedRoom: null });
        await this.deleteBan(user.id);

        const room = await this.roomRepository.findOneBy({ name: roomName });
        client.to(room.name).emit('getmessage', {
            type: 'not',
            roomname: roomName,
            userid: userId,
            username,
            avatar: null,
            msg: `${username}님이 ${roomName}에서 나가셨습니다.`
        })
        await this.deleteBanList(username, roomName);
        let Administrator: User;
        // 마지막 한명이 나갔을 경우 방 폭파
        if (await this.getUsersInRoom(room.id) === 0) {
            await this.roomRepository.delete({
                id: room.id
            })
            return ;
        }
        // 아닌 경우1 : 방 폭파를 한다? => 위 로직과 동일
        // 아닌 경우2 (나간 사람이 channelOwner인 경우)
        //      다음 멤버를 channelOwner, Administrator로 지정 (Administrator가 다른 유저인 경우 유지)
        else if (room.channelOwner.username === user.username) {
            let index = 0;
            Administrator = room.Administrator.username === user.username ? room.members[0] : room.Administrator;
            await this.roomRepository.update(room.id, {
                Administrator,
                channelOwner: room.members[0]
            });
            if (this.isUserInBan(room.members[0].username, room.name)) {
                this.deleteBanList(room.members[0].username, room.name);
                await this.deleteBan(room.members[0].id);
            }
            client.to(room.name).emit('changeadmin', {
                roomname: room.name,
                admin: room.Administrator.username,
                owner: room.channelOwner.username
            })
        }
        // 아닌 경우 3 (나간 사람이 Administrator인 경우)
        //      ChannelOwner를 Administrator로 다시 지정
        else if (room.Administrator.username === username) {
            Administrator = room.channelOwner;
            await this.roomRepository.update(room.id, {
                Administrator
            })
            client.to(room.name).emit('changeadmin', {
                roomname: room.name,
                admin: room.Administrator.username,
                owner: room.channelOwner.username
            })
        }
    }

    async getUsersInRoom(roomId) {
        return await this.userRepository.createQueryBuilder("user")
            .where("user.joinedRoomId = :id", { id: roomId })
            .getCount();
    }

    async banUser(username, roomName, res) {
        try {
            const room = await this.roomRepository.findOneBy({ name: roomName });
            // 그냥 null로 바꿨을 때 postman에서 어떻게 뜨는지,,,?
            await this.userRepository.update({ username }, {
                bannedRoom: {
                    id: room.id
                }
            });
            const roomname = room.name;
            if (this.banList.get(roomname) === null) this.banList.set(roomname, [username]);
            else this.banList.get(roomname).push(username);
            res.sendStatus(200);
        } catch {
            res.sendStatus(500);
        }
    }

    public addRoomList(userId: number, roomname: string) {
        if (this.roomList.get(userId) === null)
            this.roomList.set(userId, [roomname]);
        else
            this.roomList.get(userId).push(roomname);
        console.log(this.roomList.get(userId));
    }

    public deleteRoomList(userId: number, roomname: string) {
        this.roomList.set(userId,
            this.roomList.get(userId).filter(deleteName => roomname !== deleteName));
    }

    public initSocket(userId: number) {
        this.roomList.set(userId, null);
    }

    public getRoomList(userId: number) : string[] {
        const user = this.userRepository.findOneBy({ id: userId });
        const result = this.roomList.get(userId);
        if (!result)
            return [];
        return result;
    }

    public isUsernameReg(userId: number) : boolean {
        return this.roomList.has(userId);
    }

    isUserInBan(username: string, roomname: string) {
        if (this.banList.get(roomname) === null) return false;
        return this.banList.get(roomname).indexOf(username) !== -1;
    }

    async delegateAdmin(username: string, roomName: string, res) {
        const room = await
            this.roomRepository.findOneBy({ name: roomName });
        const Administrator = await this.userRepository.findOneBy({ username });
        await this.roomRepository.update(room.id, {
            Administrator
        });
        res.header().status(200).send();
    }

    async deleteBan(userId: number) {
        await this.userRepository.update({ id: userId }, { bannedRoom: null });
    }

    async getMembers(roomname: string) {
        const room = await this.roomRepository.findOneBy({ name: roomname });
        return room.members;
    }

    private deleteBanList(username: string, roomName: string) {
        if (this.isUserInBan(username, roomName)) {
            if (this.banList.get(roomName).length === 0)
                this.banList.delete(roomName);
            else
                this.banList.set(roomName,
                    this.banList.get(roomName).filter(deleteName => username !== deleteName));
        }
    }


}
