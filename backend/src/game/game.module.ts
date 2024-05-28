import { Module } from '@nestjs/common';
import { GameGateWay } from './game.gateway';
import { GameLogic } from './game.gameLogic';
import { GameService } from './game.service';

@Module({
  providers: [GameGateWay, GameService, GameLogic],
})
export class GameModule {}
