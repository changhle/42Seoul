import { Body, Controller, Get, Param, Post, Res } from "@nestjs/common";
import { FriendService } from "./friend.service";
import { User } from "../user/user.entity";
import { UserRepository } from "../user/user.repository";

@Controller()
export class FriendController {
    constructor(private friendService: FriendService) {}

    @Get('/friendsList/:id')
    getAllFriend(@Param('id') id: number) {
        return this.friendService.getAllFriend(id);
    }

    @Post('/deleteFriend/:id')
    deleteFriend(@Param('id') userId: number,
                 @Body('userid') friendId: number,
                 @Res() res) {
        this.friendService.deleteFriend(userId, friendId);
        res.sendStatus(200);
    }
}
