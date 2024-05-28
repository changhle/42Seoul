import { Module } from '@nestjs/common';
import { FriendService } from './friend.service';
import { FriendController } from './friend.controller';
import { TypeOrmModule } from "@nestjs/typeorm";
import { Friend } from "./friend.entity";
import { FriendRepository } from "./friend.repository";
import { User } from "../user/user.entity";
import { UserRepository } from "../user/user.repository";

@Module({
  imports: [
    TypeOrmModule.forFeature([Friend]),
    TypeOrmModule.forFeature([User])
  ],
  controllers: [FriendController],
  providers: [FriendService, FriendRepository, UserRepository]
})
export class FriendModule {}
