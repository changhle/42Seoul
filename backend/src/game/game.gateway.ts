import {
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer,
} from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';
import { GameService } from './game.service';

@WebSocketGateway({
  namespace: 'game',
  cors: {
    origin: [
      'http://localhost:8080',
      'http://127.0.0.1:8080',
      'http://localhost:5500',
    ],
    methods: ['GET', 'POST'],
    credentials: true,
  },
})
export class GameGateWay {
  @WebSocketServer() server: Server;
  constructor(private gameService: GameService) {}

  handleConnection() {
    console.log(
      'client Connected========================================================',
    );
  }

  handleDisconnect() {
    console.log(
      'client Disconnected========================================================',
    );
  }

  @SubscribeMessage('message')
  handleMessage(socket: Socket, data: any) {
    console.log(data);
    socket.emit('position', data);
  }

  @SubscribeMessage('ready')
  async readyMessage(socket: Socket, data: any) {
    console.log(data);
    const userCnt = this.gameService.applyGame(socket, data);
    if (userCnt === 2) {
      const roomInfo = this.gameService.createRoom(socket, data);
      const sockets = await this.server
        .in(String(roomInfo.roomNum))
        .fetchSockets();
      for (let idx = 0; idx < sockets.length; ++idx) {
        sockets[idx].emit('set', {
          roomNum: roomInfo.roomNum,
          team: idx,
        });
      }
    }
  }

  @SubscribeMessage('cancel')
  cancelMessage(socket: Socket) {
    this.gameService.cancelGame(socket);
    socket.emit('cancelAck');
  }

  @SubscribeMessage('play')
  async playMessage(socket: Socket, data: any) {
    console.log('id : ', socket.id);
    console.log(data);
    if (this.gameService.checkTimeout(data))
      return this.server.to(String(data.roomNum)).emit('timeOut');
    const playInfo = this.gameService.playGame(data);
    if (playInfo.winner !== undefined)
      this.server.to(String(data.roomNum)).emit('end', playInfo);
    this.server.to(String(data.roomNum)).emit('update', playInfo);
  }
}
