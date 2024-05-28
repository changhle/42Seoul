import { UserStatus } from "../user/user-status.enum";
import { Game } from "../game/game.entity";

export class FriendsListDto {
    username: string;
    status: UserStatus;
    avatar: string;


    constructor(username: string, avatar: string, status: UserStatus) {
        this.username = username;
        this.avatar = avatar;
        this.status = status;
    }
}