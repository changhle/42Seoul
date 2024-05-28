import {
    OnGatewayConnection,
    OnGatewayDisconnect,
    SubscribeMessage,
    WebSocketGateway,
    WebSocketServer
} from "@nestjs/websockets";
import { Server, Socket } from "socket.io";
import { SendMsgDto } from "../dto/send-msg.dto";
import { RoomService } from "../chat/room.service";
import { RoomRepository } from "../chat/room.repository";
import { UserChatDto } from "../dto/user-chat.dto";
import { UserRepository } from "../user/user.repository";
import { DelegateAdminDto } from "../dto/delegate-admin.dto";
import { ConnectSocketDto } from "../dto/connect-socket.dto";
import { SocketClientDto } from "../dto/socket-client.dto";
import { FriendService } from "../friend/friend.service";
import { UserStatus } from "../user/user-status.enum";
import { GetUserDto } from "../dto/get-user.dto";
import { UserService } from "../user/user.service";

@WebSocketGateway(4242, {cors : {
    origin: ["http://localhost:8080", "http://127.0.0.1:8080"],
    methods: ["GET", "POST"],
    credentials: true
}})
export class EventsGateway implements OnGatewayConnection, OnGatewayDisconnect{

    // userid, SocketClientDto
    private connectedClients: Map<number, SocketClientDto> = new Map();

    constructor(
        private roomService: RoomService,
        private roomRepository: RoomRepository,
        private userRepository: UserRepository,
        private friendService: FriendService,
        private userService: UserService
    ) {}

    @WebSocketServer()
    server: Server;

    async handleConnection(client: Socket) {
        const userId = parseInt(<string>client.handshake.query.userid);
        await this.userRepository.updateUserStatus(userId, UserStatus.ONLINE);
        this.connectedClients.set(userId, {
            clientId: client.id,
            socket: client
        });
        if (this.roomService.isUsernameReg(userId)) {
            const roomList = this.roomService.getRoomList(userId);
            client.join(roomList);
        } else {
            this.roomService.initSocket(userId);
        }
    }

    async handleDisconnect(client: Socket) {
        const userId = parseInt(<string>client.handshake.query.userid);
        await this.userRepository.updateUserStatus(userId, UserStatus.OFFLINE);
        this.connectedClients.delete(userId);
    }

    @SubscribeMessage('enterroom')
    async enterRoom(client: Socket, data: UserChatDto) {
        let roomname = data.roomname;
        const room = await this.roomRepository.findOneBy({ name: roomname });
        let status: string, admin: string, owner: string, members: GetUserDto[];

        // 방제에 특수문자 못넣게
        if (data.type === 'dm') {
            const userFrom = await this.userRepository.findOneBy({ id: data.userid });
            const userTo = await this.userRepository.findOneBy({ username: data.roomname});
            roomname = this.getDmRoomName(roomname, userFrom.username);
            if (client.rooms.has(roomname)) return ;
            if (!(this.roomService.getRoomList(data.userid).includes(roomname) &&
                    this.roomService.getRoomList(userTo.id).includes(roomname))) {
                const clientTo: Socket = this.connectedClients.get(userTo.id).socket;
                status = "public";
                admin = null;
                owner = null;
                members = this.userService.usersToDto([userFrom, userTo]);
                this.roomService.addRoomList(userTo.id, roomname);
                clientTo.join(roomname);
            }
        }
        else if (data.type === 'msg') {
            if (client.rooms.has(roomname)) return ;
            await this.roomService.enterRoom(data.userid, roomname, client);
            status = room.status;
            admin = room.Administrator.username;
            owner = room.channelOwner.username;
            members = this.userService.usersToDto(room.members);
        }
        client.join(roomname);
        this.roomService.addRoomList(data.userid, roomname);
        return {
            type: data.type,
            roomname,
            status,
            admin,
            owner,
            members
        }
    }

    private getDmRoomName(roomname: string, username: string) {
        const list = [roomname, username].sort();
        return list[0] + " \| " + list[1];
    }

    @SubscribeMessage('sendmessage')
    async sendMessage(client: Socket, data: SendMsgDto) {
        const user = await this.userRepository.findOneBy({ id: data.userid });
        if (data.type === 'msg' && this.roomService.isUserInBan(user.username, data.roomname)) {
            return {
                ban: true
            };
        }
        else {
            const sliceIndx = user.avatar.search('upload');
            client.to(data.roomname).emit('getmessage', {
                type: data.type,
                roomname: data.roomname,
                userid: data.userid,
                username: user.username,
                avatar: user.avatar.slice(sliceIndx),
                msg: data.msg
            });
            return {
                ban: false
            };
        }
    }

    @SubscribeMessage('exitroom')
    async exitRoom(client: Socket, data: UserChatDto) {
        if (data.type === 'msg')
            await this.roomService.exitRoom(data.userid, data.roomname, client);
        this.roomService.deleteRoomList(data.userid, data.roomname);
        client.leave(data.roomname);
    }

    @SubscribeMessage('delegateadmin')
    async delegateAdmin(client: Socket, data: DelegateAdminDto) {
        const room = await this.roomRepository.findOneBy({ name: data.roomname });
        const admin = await this.userRepository.findOneBy({ id: data.userid });
        const owner = room.channelOwner.username;
        await this.roomRepository.update(room.id, {
            Administrator: admin
        });
        this.server.to(data.roomname).emit('changeadmin', {
            roomname: data.roomname,
            admin: admin.username,
            owner
        })
    }

    @SubscribeMessage('addfriend')
    async addFriend(client: Socket, data: ConnectSocketDto) {
        // user1, user2 서로 친구로 등록
        await this.friendService.addFriend(data.userfrom, data.userto);
        const userToId = (await this.userRepository.findOneBy({ username: data.userto })).id;
        const clientTo = this.connectedClients.get(userToId).socket;
        client.emit('fetchfriend', { result: 200 });
        clientTo.emit('fetchfriend', { result: 200 });
    }

    @SubscribeMessage('connectsocket')
    async connectSocket(client: Socket, data: ConnectSocketDto) {
        if (data.type === 'friend') {
            const msg = await this.connectFriend(client, data);
            return { msg };
        } else if (data.type === 'game') {

        }
    }

    // 이거 재활용하면 될듯
    // 게임: 상대 유저의 상태 (ONLINE일 경우에만 전송)
    async connectFriend(client: Socket, data: ConnectSocketDto): Promise<string> {
        const friend = await this.userRepository.findOneBy({username: data.userto});
        const user = await this.userRepository.findOneBy({ id: data.userfrom });
        // 없는 친구를 추가하려고 하는 경우
        if (friend === null) {
            return "존재하지 않는 유저입니다.";
        }
        // 자기자신을 추가하려고 하는 경우
        else if (friend.id === data.userfrom)
            return "자기자신을 추가할 수 없습니다.";
        // 이미 추가된 친구일 경우 null 반환
        const friendId = friend.id;
        for (const friends of user.friendList) {
            if (friends.id === friendId) {
                return "이미 추가한 유저입니다.";
            }
        }
        const clientTo = this.connectedClients.get(friendId).socket;
        // type, userId, username 세 개 보내면 됨
        client.to(clientTo.id).emit('notification', {
            type: 'friend',
            userid: data.userfrom,
            username: user.username
        })
        return "success";
    }
}