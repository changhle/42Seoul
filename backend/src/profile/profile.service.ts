import { HttpException, Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { randomUUID } from 'crypto';
import { writeFileSync } from 'fs';
import { extname, join } from 'path';
import { Repository } from 'typeorm';
import { User } from 'src/user/user.entity';
import { ProfileDto, ProfileReturnDto } from './profile.dto';

@Injectable()
export class ProfileService {
  constructor(
    @InjectRepository(User) private userRepository: Repository<User>,
  ) {}

  private async updateAvatarPathDB(userName: string, imagePath: string) {
    try {
      return await this.userRepository
        .createQueryBuilder()
        .update(User)
        .set({ avatar: imagePath })
        .where('username = :userName', { userName: userName })
        .execute();
    } catch (e) {
      throw new HttpException('데이터 저장 실패', 606, {
        cause: new Error(`DB 업데이트 실패: ${e}`),
      });
    }
  }

  private async findImagePath(userName: string): Promise<string> {
    try {
      const found = await this.userRepository
        .createQueryBuilder('user')
        .select('avatar')
        .where('username = :userName', { userName: userName })
        .getRawOne();
      return found.avatar;
    } catch (e) {
      throw new HttpException('유효한 이름이 아닙니다.', 608, {
        cause: new Error(`DB search 실패: ${e}`),
      });
    }
  }

  private async foundProfileName(userName: string): Promise<string> {
    try {
      const found = await this.userRepository
        .createQueryBuilder('user')
        .select()
        .where('user.username = :userName', { userName: userName })
        .getRawOne();
      return found.username;
    } catch (error) {
      throw new HttpException('유효한 ID가 아닙니다.', 601, {
        cause: new Error('DB에 존재하지 않는 ID'),
      });
    }
  }

  private async updateDB({ userName, imagePath }): Promise<void> {
    await this.updateAvatarPathDB(userName, imagePath);
  }

  private saveFileToDiskSync({ imagePath, file }): void {
    try {
      writeFileSync(imagePath, file.buffer);
    } catch (error) {
      throw new HttpException('세팅에 실패했습니다.', 604, {
        cause: new Error(`파일 쓰기 실패 : ${error.code}`),
      });
    }
  }

  private async fileSave(
    findName: string,
    file: Express.Multer.File,
  ): Promise<string> {
    const imagePath = join(
      __dirname,
      '../../upload/profile/image',
      randomUUID() + extname(file.originalname),
    );
    this.saveFileToDiskSync({ imagePath, file });
    await this.updateDB({ userName: findName, imagePath });
    return imagePath;
  }

  private async updateUserName({ userName, newName }) {
    try {
      const result = await this.userRepository
        .createQueryBuilder()
        .update(User)
        .set({ username: newName })
        .where('username = :userName', { userName: userName })
        .execute();
      return result;
    } catch (e) {
      if (e.detail.includes('already exists')) {
        throw new HttpException('이미 존재하는 이름입니다.', 611, {
          cause: new Error('DB 이름 쓰기 실패'),
        });
      }
      throw new HttpException('세팅에 실패했습니다.', 114, {
        cause: new Error(`이름 쓰기 실패`),
      });
    }
  }

  async updateProfile(
    profileDto: ProfileDto,
    file: Express.Multer.File,
  ): Promise<ProfileReturnDto> {
    if (!file && !profileDto.newName)
      throw new HttpException('세팅 정보를 입력해 주세요.', 601, {
        cause: new Error('유저 이름 & 빈 파일'),
      });

    const findName = profileDto.newName
      ? profileDto.newName
      : profileDto.userName;
    if (profileDto.newName) {
      const isUpdated = await this.updateUserName(profileDto);
      if (isUpdated.affected === 0) {
        throw new HttpException('유효한 네임이 아닙니다.', 608, {
          cause: new Error('유저 이름 없음'),
        });
      }
    }
    let imagePath = await this.findImagePath(findName);
    if (file) imagePath = await this.fileSave(findName, file);
    const sliceIndx = imagePath.search('upload');
    return {
      userName: findName,
      imagePath: imagePath.slice(sliceIndx),
    };
  }
}
