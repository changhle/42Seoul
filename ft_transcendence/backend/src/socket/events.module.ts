import { Module } from "@nestjs/common";
import { EventsGateway } from "./events.gateway";
import { RoomController } from "../chat/room.controller";
import { TypeOrmModule } from "@nestjs/typeorm";
import { User } from "../user/user.entity";
import { Room } from "../chat/room.entity";
import { RoomService } from "../chat/room.service";
import { RoomRepository } from "../chat/room.repository";
import { UserRepository } from "../user/user.repository";
import { FriendService } from "../friend/friend.service";
import { FriendRepository } from "../friend/friend.repository";
import { Friend } from "../friend/friend.entity";
import { UserService } from "../user/user.service";

@Module({
    imports: [
        TypeOrmModule.forFeature([Room]),
        TypeOrmModule.forFeature([User]),
        TypeOrmModule.forFeature([Friend])
    ],
    controllers: [RoomController],
    providers: [
        EventsGateway,
        RoomService,
        FriendService,
        UserService,
        RoomRepository,
        UserRepository,
        FriendRepository]
})
export class EventsModule {}
