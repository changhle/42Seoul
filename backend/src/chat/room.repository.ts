import { DataSource, Repository } from "typeorm";
import { InjectRepository } from "@nestjs/typeorm";
import { Room } from "./room.entity";

export class RoomRepository extends Repository<Room> {
    constructor(@InjectRepository(Room) private dataSource: DataSource) {
        super(Room, dataSource.manager)
    }


}
