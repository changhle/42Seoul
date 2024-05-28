import { Module } from '@nestjs/common';
import { AuthService } from './auth.service';
import { AuthController } from './auth.controller';
import { JwtModule } from '@nestjs/jwt';
import { FtStrategy } from './strategies/ft.strategy';
import { UserService } from 'src/user/user.service';
import { UserModule } from 'src/user/user.module';
import { UserRepository } from 'src/user/user.repository';
import { TypeOrmModule } from '@nestjs/typeorm';
import { User } from 'src/user/user.entity';

@Module({
	imports: [
		// PassportModule.register({ defaultStrategy: 'jwt'}),
		JwtModule.register({
			secret: 'transcendence',
			signOptions: {
				expiresIn: 3600
			}
		}),
		TypeOrmModule.forFeature([User]),
		UserModule,
	],
	controllers: [AuthController],
	providers: [
		FtStrategy,
		// JwtStrategy,
		AuthService,
		UserService,
		UserRepository,
	],
	exports: [
		// JwtStrategy,
		// PassportModule
	]
})
export class AuthModule {}