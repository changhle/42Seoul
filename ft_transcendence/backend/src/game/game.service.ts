import { Injectable } from '@nestjs/common';
import { Socket } from 'socket.io';
import { GameLogic } from './game.gameLogic';

class User {
  id: number;
}
interface PlaySocketDto {
  roomNum: number;
  team: boolean;
  y: number;
}

export class RoomInfo {
  roomNum: number;
  userBarX: number;
  userBarY: number;
  opponentBarX: number;
  opponentBarY: number;
  ballX: number;
  ballY: number;
  width: number;
  height: number;
  startTime: number;
  userUpdateTime: number;
  opponentUpdateTime: number;
}

@Injectable()
export class GameService {
  private rooms: Map<number, RoomInfo>;
  private roomIdx: number;
  private userCnt: number;
  private tmpUser: User;
  private timeOutMs: number;

  constructor(private gameLogic: GameLogic) {
    this.roomIdx = 0;
    this.userCnt = 0;
    this.timeOutMs = 20000;
    this.rooms = new Map<number, RoomInfo>();
  }

  applyGame(socket: Socket, user: User): number {
    if (this.userCnt === 0) {
      this.tmpUser = user;
      ++this.userCnt;
      socket.join(String(this.roomIdx));
      return this.userCnt;
    } else {
      socket.join(String(this.roomIdx));
    }
    return ++this.userCnt;
  }

  cancelGame(socket: Socket) {
    socket.leave(String(this.roomIdx));
  }

  createRoom(socket: Socket, user: User) {
    this.userCnt = 0;
    const nowTime = Date.now();
    const newRoom = {
      roomNum: this.roomIdx,
      userId: this.tmpUser.id,
      userBarX: 0,
      userBarY: 0,
      opponentId: user.id,
      opponentBarX: 0,
      opponentBarY: 0,
      ballX: 300,
      ballY: 200,
      width: 600,
      height: 400,
      startTime: nowTime + 2000,
      userUpdateTime: nowTime,
      opponentUpdateTime: nowTime,
    };
    this.rooms.set(this.roomIdx, newRoom);
    this.roomIdx++;
    this.userCnt = 0;
    this.gameLogic.ReadyGame(newRoom.roomNum, newRoom.startTime);
    return newRoom;
  }

  checkTimeout({ roomNum, team }) {
    const room = this.rooms.get(roomNum);
    const nowTime = Date.now();

    if (nowTime - room.userUpdateTime > this.timeOutMs) return true;
    if (nowTime - room.opponentUpdateTime > this.timeOutMs) return true;
    if (team === 0) room.userUpdateTime = nowTime;
    else room.opponentUpdateTime = nowTime;
    return false;
  }

  playGame(data: PlaySocketDto) {
    return this.gameLogic.playGame(data);
  }
}
