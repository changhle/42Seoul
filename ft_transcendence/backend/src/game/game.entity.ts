import { Column } from 'typeorm';

export class Game {
  @Column()
  wins: number;

  @Column()
  loses: number;

  @Column()
  ladderLevel: number;

  @Column()
  achieve: string;
}
