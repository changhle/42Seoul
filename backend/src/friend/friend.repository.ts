import { DataSource, Repository } from "typeorm";
import { InjectRepository } from "@nestjs/typeorm";
import { Friend } from "./friend.entity";

export class FriendRepository extends Repository<Friend> {
    constructor(@InjectRepository(Friend) private dataSource: DataSource) {
        super(Friend, dataSource.manager) // 변경
    }
}
