import { BaseEntity, Column, Entity, JoinColumn, OneToMany, OneToOne, PrimaryGeneratedColumn } from "typeorm";
import { User } from "../user/user.entity";
import { RoomStatus } from "./room-status.enum";
import { MainUserDto } from "../dto/main-user.dto";

@Entity()
export class Room extends BaseEntity {

    @PrimaryGeneratedColumn()
    id: number;

    @Column()
    name: string;

    @Column()
    password: string;

    @Column()
    status: RoomStatus;

    @OneToOne(type => User, {eager: true})
    @JoinColumn()
    channelOwner: User;

    @OneToOne(type => User, {eager: true})
    @JoinColumn()
    Administrator: User;

    @OneToMany(type => User, members => members.joinedRoom, {eager: true})
    members: User[];

    @OneToMany(type => User, banList => banList.bannedRoom, {eager: true})
    banList: User[];
}