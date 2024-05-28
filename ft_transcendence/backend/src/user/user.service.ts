import { Injectable } from '@nestjs/common';
import { UserRepository } from './user.repository';
import { UserStatus } from './user-status.enum';
import { MainUserDto } from '../dto/main-user.dto';
import { User } from './user.entity';
import { join } from 'path';
import { GetUserDto } from "../dto/get-user.dto";

@Injectable()
export class UserService {
  constructor(private userRepository: UserRepository) {}

    async findMainUserById(id: number): Promise<MainUserDto> {
        const user = await this.findUserById(id);
        const sliceIndx = user.avatar.search('upload');
        return {
            id: user.id,
            username: user.username,
            avatar: user.avatar.slice(sliceIndx),
        };
    }

    public usersToDto(users: User[]) {
        let result : GetUserDto[] = [];
        for (const user of users) {
            const sliceIndx = user.avatar.search('upload');
            result.push({
                id: user.id,
                status: user.status,
                username: user.username,
                avatar: user.avatar.slice(sliceIndx)
            })
        }
        return result;
    }

  /* test */
  async getAllUser(): Promise<User[]> {
    return await this.userRepository.find();
  }

  async createUser(intraId: string, accessToken: string): Promise<User> {
    let user = await this.userRepository.findOneBy({ intraId: intraId });
    if (!user) {
      user = this.userRepository.create({
        token: accessToken,
        // twofactorauth: true,
        intraId: intraId,
        username: intraId,
        avatar: '/upload/profile/image/default.png',
        game: {
          wins: 0,
          loses: 0,
          ladderLevel: 0,
          achieve: '0',
        },
        status: UserStatus.ONLINE,
      });
    }
    user.status = UserStatus.ONLINE;
    this.userRepository.save(user);
    return user;
  }

  async addUser(user: User): Promise<User> {
    const found = await this.userRepository.findBy({ username: user.username });
    // 차후 변경
    if (found.length >= 1) return null;
    return await this.userRepository.save(user);
  }

  async findUserById(id: number): Promise<User> {
    return await this.userRepository.findOneBy({ id });
  }

  async findUserByIntraId(username: string): Promise<User> {
    return await this.userRepository.findOneBy({ username });
  }

  initUser() {
    const defaultAvatarPath = join(
      __dirname,
      '../../',
      'upload/profile/image/default.png',
    );

    this.addUser(
      this.userRepository.create({
        token: '1234',
        intraId: 'minslee',
        username: 'minslee',
        avatar: defaultAvatarPath,
        game: {
          wins: 1,
          loses: 1,
          ladderLevel: 1,
          achieve: '1',
        },
        status: UserStatus.ONLINE,
      }),
    );
    this.addUser(
      this.userRepository.create({
        token: '1234',
        intraId: 'kyolee',
        username: 'kyolee',
        avatar: defaultAvatarPath,
        game: {
          wins: 2,
          loses: 2,
          ladderLevel: 2,
          achieve: '2',
        },
        status: UserStatus.OFFLINE,
      }),
    );
    this.addUser(
      this.userRepository.create({
        token: '1234',
        intraId: 'changhle',
        username: 'changhle',
        avatar: defaultAvatarPath,
        game: {
          wins: 3,
          loses: 3,
          ladderLevel: 3,
          achieve: '3',
        },
        status: UserStatus.GAMING,
      }),
    );
  }

  /* create dummy
    {
        "token": "1234",
        "intraId": "minslee",
        "username": "minslee",
        "avatar": "minslee.png",
        "game": {
            "wins": 1,
            "loses": 1,
            "ladderLevel": 1,
            "achieve": "1"
            },
        "status": "ONLINE"
    }
    {
        "token": "1234",
        "intraId": "kyolee",
        "username": "kyolee",
        "avatar": "kyolee.png",
        "game": {
            "wins": 2,
            "loses": 2,
            "ladderLevel": 2,
            "achieve": "2"
        },
        "status": "ONLINE"
    }
    {
        "token": "1234",
        "intraId": "changhle",
        "username": "changhle",
        "avatar": "changhle.png",
        "game": {
            "wins": 3,
            "loses": 3,
            "ladderLevel": 3,
            "achieve": "3"
        },
        "status": "ONLINE"
    }
     */
}
