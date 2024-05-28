import { Body, Controller, Param, Post } from "@nestjs/common";
import { Get } from "@nestjs/common";
import { MainUserDto } from "../dto/main-user.dto";
import { UserService } from "./user.service";
import { User } from "./user.entity";

@Controller()
export class UserController {
    constructor(
        private userService: UserService,
    ) {}

    @Get('/user/:id')
    mainUser(@Param('id') id: number) : Promise<MainUserDto> {
        return this.userService.findMainUserById(id);
    }

    // 로그인 후 등록할 것
    @Post('/test/addUser')
    addUser(@Body() user: User): Promise<User> {
        return this.userService.addUser(user);
    }

    // 이건 걍 테스트용 (나중에 삭제해도 됨)1
    @Get('/test/allUser')
    getAllUsers(): Promise<User[]> {
        return this.userService.getAllUser();
    }

    @Post('/test/initUser')
    initUser() {
        this.userService.initUser();
    }
}
