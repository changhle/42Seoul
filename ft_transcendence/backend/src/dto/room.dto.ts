export class RoomDto {
    userId: number;
    name: string;
    type: RoomType;
    password: string;
}

export enum RoomType {
    Room = "room",
    DM = "dm",
    Announce = "announce"
}