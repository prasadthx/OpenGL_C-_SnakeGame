//
// Created by prasad on 5/16/21.
//

#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define MAX 60

void initGrid(int, int);
void drawGrid();
void drawSnake();
void drawFood();
void random(int&, int&);

#endif //SNAKE_GAME_GAME_H
