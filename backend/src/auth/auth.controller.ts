import { Body, Controller, Get, HttpStatus, Post, Query, Request, Response, UnauthorizedException, UseGuards } from '@nestjs/common';
// import { FtAuthGuard } from './guards/ft.guard';
import { AuthService } from './auth.service';
import { TwoFactorAuthCodeDto } from '../dto/twoFactorAuthCodeDto';
import { AuthGuard } from '@nestjs/passport';
import { UserService } from 'src/user/user.service';
import { UserStatus } from 'src/user/user-status.enum';
import { UserRepository } from 'src/user/user.repository';

@Controller('auth')
export class AuthController {
	constructor(
		private readonly authService: AuthService,
		private readonly userService: UserService,
		private readonly userRepository: UserRepository,
		) {}

	@Get('42login')
	@UseGuards(AuthGuard('ft'))
	userLogin(@Request() req) {
	}

	@Get('redirect')
	@UseGuards(AuthGuard('ft'))
	async redirect(@Request() req, @Response() res) {
		const accessToken = await this.authService.generateToken(req.user);
		const user = await this.userService.createUser(req.user, accessToken.accessToken);
		console.log(user);
		if (user.twofactorauth)
			res.redirect(`http://127.0.0.1:8080/fa2?id=${user.id}`);
		else
		res.redirect(`http://127.0.0.1:8080/callback?id=${user.id}`);
			// res.status(HttpStatus.OK).json({ id: user.id });
	}
	
	@Get('getOtpAuthUrl')
	async getOtpAuthUrl(@Request() req, @Response() res, @Query('id') id: number) {
		let user = await this.userService.findUserById(id);
		const otpAuthUrl = await this.authService.generateTwoFactorAuthSecret(user);
		console.log(id);
		res.json({
			id: id,
			otpAuthUrl
		});
	}

	@Get('verify')
	async verify(
		@Response() res,
		@Query('twoFactorAuthCode') twoFactorAuthCode: string,
		@Query('id') id: number
		) {
		const user = await this.userService.findUserById(id);
		const isCodeValidated = await this.authService.isTwoFactorAuthCodeValid(
			user.secretKey,
			twoFactorAuthCode
			);
		console.log(isCodeValidated);
		if (!isCodeValidated)
			res.status(HttpStatus.BAD_REQUEST).json({ id: id });
		else
			res.status(HttpStatus.OK).json({ id: id });
	}

	@Get('getToken')
	async getToken(@Response() res, @Query('id') id: number) {
		const user = await this.userService.findUserById(id);
		res.json({
			id: user.id,
			token: user.token,
		});
	}

	@Get('42logout')
	async userLogout(@Query('id') id: number) {
		let user = await this.userService.findUserById(id);
		user.status = UserStatus.OFFLINE;
		this.userRepository.save(user);
		return "logout success"
	}
}
