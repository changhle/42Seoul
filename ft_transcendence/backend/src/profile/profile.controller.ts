import {
  Body,
  Controller,
  Post,
  Response,
  UploadedFile,
  UseInterceptors,
} from '@nestjs/common';
import { ProfileService } from './profile.service';
import { FileInterceptor } from '@nestjs/platform-express';
import { ProfileValidationPipe } from './profile.validation.pipe';
import { ProfileDto } from './profile.dto';

@Controller('profile')
export class ProfileController {
  constructor(private profileService: ProfileService) {}

  @Post('/update')
  @UseInterceptors(FileInterceptor('file'))
  async updateProfile(
    @Body(ProfileValidationPipe) profileDto: ProfileDto,
    @UploadedFile() file: Express.Multer.File,
    @Response() res,
  ) {
    const result = await this.profileService.updateProfile(profileDto, file);
    return res.json(result);
  }
}
