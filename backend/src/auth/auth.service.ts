import { Injectable } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { copyFileSync } from 'fs';
import { authenticator } from 'otplib';
import { toFileStream } from 'qrcode'
import { User } from 'src/user/user.entity';
import { UserRepository } from 'src/user/user.repository';

@Injectable()
export class AuthService {
	constructor(
		private jwtService: JwtService,
		private userRepository: UserRepository,
	) {}

	async generateToken(username: string): Promise<{accessToken: string}> {
		const payload = { username: username };
		const accessToken = await this.jwtService.sign(payload);

		return { accessToken }
	}

	public generateTwoFactorAuthSecret(user: User) {
		if (!user.secretKey)
		{
			user.secretKey = authenticator.generateSecret();
			this.userRepository.save(user);
		}
		const otpAuthUrl = authenticator.keyuri('', '', user.secretKey);

		return otpAuthUrl;
	}

	public pipeQrCodeStream(stream: Response, otpAuthUrl: string) {
		return toFileStream(stream, otpAuthUrl);
	}

	public async isTwoFactorAuthCodeValid(secretKey: string, twoFactorAuthCode: string) {
		return authenticator.verify({
			token: twoFactorAuthCode,
			secret: secretKey,
		})
	}
}
