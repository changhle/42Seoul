import { BaseEntity, Column, Entity, ManyToMany, ManyToOne, OneToMany, PrimaryGeneratedColumn, Unique } from "typeorm";
import { Game } from "../game/game.entity";
import { UserStatus } from "./user-status.enum";
import { Friend } from "../friend/friend.entity";
import { Room } from "../chat/room.entity";

@Entity()
export class User extends BaseEntity {
    // 테스트용이라 uuid 뺌
    // 실전에선 꼭 넣을것
    @PrimaryGeneratedColumn()
    id: number;

    @Column()
    token: string;

    @Column({ nullable: true })
    secretKey: string;

    @Column({ default: false })
    twofactorauth: boolean;

    @Column()
    intraId: string;

    @Column()
    username: string;

    @Column()
    avatar: string;

    @Column(Type => Game)
    game: Game;

    @Column()
    status: UserStatus;

    @OneToMany(type => Friend, friendList => friendList.user, {eager: true})
    friendList: Friend[];

    @ManyToOne(type => Room, joinedRoom => joinedRoom.members, {eager: false, cascade: true})
    joinedRoom: Room;

    @ManyToOne(type => Room, bannedRoom => bannedRoom.banList, {eager: false})
    bannedRoom: Room
}
