import { MainUserDto } from "./main-user.dto";

export class GetChannelDto {
    id: number;
    name: string;
    password: string;
    status: string;
    member: MainUserDto;

    constructor(id: number, name: string, password: string, status: string, member: MainUserDto) {
        this.id = id;
        this.name = name;
        this.password = password;
        this.status = status;
        this.member = member;
    }
}