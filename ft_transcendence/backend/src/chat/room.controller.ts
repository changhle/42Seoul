import { Body, Controller, Get, HttpStatus, Param, Post, Res } from "@nestjs/common";
import { RoomService } from "./room.service";
import { CreateRoomDto } from "../dto/create-room.dto";
import { Room } from "./room.entity";
import { MainUserDto } from "../dto/main-user.dto";
import { GetChannelDto } from "../dto/get-channel.dto";
import { Socket } from "socket.io";

@Controller()
export class RoomController {
    constructor(
        private roomService: RoomService
    ) {}

    @Post('/createRoom')
    createRoom(@Body() createRoomDto: CreateRoomDto,
               @Res() res) {
        return this.roomService.createRoom(createRoomDto, res);
    }

    @Get('/ChennelList')
    async getAllRooms(@Res() res, client: Socket) {
        return this.roomService.ChennelList(res);
    }

    // 수정요구사항 - 2번 해결
    @Post('/updateMember')
    async updateMember(@Body('roomname') roomname: string) {
        return await this.roomService.getMembers(roomname);
    }

    @Post('/banUser')
    banUser(@Body('userName') username: number,
            @Body('chennelName') roomName: number,
            @Res() res) {
        return this.roomService.banUser(username, roomName, res);
    }

    /* test */
    @Post('/room/banDelete/:id')
    banDelete(@Param('id') userId: number) {
        return this.roomService.deleteBan(userId);
    }

    @Post('/delegateAdmin')
    delegateAdmin(@Body('userName') username: string,
            @Body('chennelName') roomName: string,
            @Res() res) {
        return this.roomService.delegateAdmin(username, roomName, res);
    }
}
