import { Module } from '@nestjs/common';
import { User } from './user.entity';
import { TypeOrmModule } from '@nestjs/typeorm';
import { UserController } from './user.controller';
import { UserService } from './user.service';
import { UserRepository } from './user.repository';
import { InitController } from './init.controller';
import { ProfileController } from 'src/profile/profile.controller';
import { ProfileService } from 'src/profile/profile.service';

@Module({
  imports: [TypeOrmModule.forFeature([User])],
  controllers: [InitController, UserController, ProfileController],
  providers: [UserService, UserRepository, ProfileService],
})
export class UserModule {}
