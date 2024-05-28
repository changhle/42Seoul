import { RoomStatus } from "../chat/room-status.enum";
import { User } from "../user/user.entity";
import { Socket } from "socket.io";

export class CreateRoomDto {
    userId: number;
    chennelName: string;
    password: string;
}