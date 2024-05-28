import { Injectable } from '@nestjs/common';
import { FriendRepository } from "./friend.repository";
import { UserRepository } from "../user/user.repository";
import { Friend } from "./friend.entity";
import { User } from "../user/user.entity";

@Injectable()
export class FriendService {
    constructor(
        private friendRepository: FriendRepository,
        private userRepository: UserRepository) {
    }

    async findFriendByUsername(username: string) {
        return await this.userRepository.findOneBy({username});
    }

    async addFriend(from: number, to: string) {
        const user1 = await this.userRepository.findOneBy({id: from});
        const user2 = await this.userRepository.findOneBy({username: to});

        await this.friendRepository.save(this.friendRepository.create({
            username: user1.username,
            avatar: user1.avatar,
            game: user1.game,
            status: user1.status,
            user: user2
        }));

        return await this.friendRepository.save(this.friendRepository.create({
            username: user2.username,
            avatar: user2.avatar,
            game: user2.game,
            status: user2.status,
            user: user1
        }));
    }

    // async addUserToFriend(username: string, id: number) {
    //     const user = await this.userRepository.findOneBy({username});
    //     const friend = await this.userRepository.findOneBy({id});
    //     if (friend === null)
    //         return null;
    //     await this.friendRepository.save(this.friendRepository.create({
    //         username: friend.username,
    //         avatar: friend.avatar,
    //         game: friend.game,
    //         status: friend.status,
    //         user
    //     }));
    //     return user;
    // }

    async getAllFriend(id: number) {
        return this.friendRepository.createQueryBuilder('friend')
            .where('friend.userId = :id', { id })
            .getMany();
    }

    async deleteFriend(userId: number, friendId: number) {
        const friendName = (await this.friendRepository.findOneBy({ id: friendId })).username;
        await this.friendRepository.createQueryBuilder("Friend")
            .delete()
            .from ("public.friend")
            .where('userId = :id', { id: userId })
            .andWhere('username = :name', { name: friendName })
            .execute();
    }
}
