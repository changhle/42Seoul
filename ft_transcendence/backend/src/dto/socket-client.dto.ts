import { Socket } from "socket.io";

export class SocketClientDto {
    clientId: string;
    socket: Socket;
}