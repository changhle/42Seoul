import { Module } from "@nestjs/common";
import { RoomController } from "./room.controller";
import { TypeOrmModule } from "@nestjs/typeorm";
import { User } from "../user/user.entity";
import { Room } from "./room.entity";
import { RoomService } from "./room.service";
import { RoomRepository } from "./room.repository";
import { UserRepository } from "../user/user.repository";
import { UserService } from "../user/user.service";

@Module({
  imports: [
    TypeOrmModule.forFeature([Room]),
    TypeOrmModule.forFeature([User]),
  ],
  controllers: [RoomController],
  providers: [
    RoomService,
    UserService,
    RoomRepository,
    UserRepository
  ]
})
export class RoomModule {}
