import { Module } from '@nestjs/common';
import { typeORMConfig } from './config/typeorm.config';
import { TypeOrmModule } from '@nestjs/typeorm';
import { UserModule } from './user/user.module';
import { EventsModule } from './socket/events.module';
import { FriendModule } from './friend/friend.module';
import { ServeStaticModule } from '@nestjs/serve-static';
import { join } from 'path';
import { AuthModule } from './auth/auth.module';
import { ConfigModule } from '@nestjs/config';
import { GameModule } from './game/game.module';

@Module({
  imports: [
    TypeOrmModule.forRoot(typeORMConfig),
    EventsModule,
    UserModule,
    FriendModule,
    AuthModule,
    GameModule,
    ConfigModule.forRoot({
      cache: true,
      isGlobal: true,
    }),
    ServeStaticModule.forRoot({
      rootPath: join(__dirname, '..', 'upload'),
      serveRoot: '/upload',
      exclude: ['/index.html'],
    }),
  ],
  controllers: [],
  providers: [],
})
export class AppModule {}
