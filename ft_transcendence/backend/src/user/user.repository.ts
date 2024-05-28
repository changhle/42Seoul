import { DataSource, Repository } from "typeorm";
import { User } from "./user.entity";
import { InjectRepository } from "@nestjs/typeorm";
import { UserStatus } from "./user-status.enum";
import { DummyDto } from "../dto/dummy.dto";
import { Room } from "../chat/room.entity";

export class UserRepository extends Repository<User> {
    constructor(@InjectRepository(User) private dataSource: DataSource) {
        super(User, dataSource.manager) // 변경
    }

    async updateUserStatus(userId: number, status: UserStatus) {
        console.log(userId);
        await this.update({id: userId}, {
            status
        })
    }

    async updateJoinedRoom(userId: number, roomId: number) {
        await this.update({id: userId}, {
            joinedRoom: {
                id: roomId
            }
        })
        // await this.createQueryBuilder()
        //     .update(User)
        //     .set({
        //         joinedRoom: room
        //     })
        //     .where("user.id = :id", { id : userId })
        //     .execute();
    }

    async createUser(user: User): Promise<User> {
        await this.save(user);
        return user;
    }

    async createNewDummyUser(dummy: DummyDto) {
        const { token, intraId, username, avatar, game, status } = dummy;
        const user = this.create({
            token,
            intraId,
            username,
            avatar,
            game,
            status
        });
        await this.save(user);
    }
}
