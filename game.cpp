//
// Created by prasad on 5/16/21.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <ctime>

int gridX, gridY;

bool food = true;

int foodX, foodY;

short snakeDirection = RIGHT;

extern bool gameOver;

int positionX = 20, positionY = 20;

void unit(int, int);

void initGrid(int x, int y){
    gridX = x;
    gridY = y;
}

void drawGrid(){
    for(int x = 0; x < gridX ; x++){
        for (int y = 0; y < gridY; y++){
            unit(x, y);
        }
    }
}

void unit(int x, int y){

    if(x==0 || y==0 || x==gridX-1 || y==gridY-1){
        glLineWidth(2.0);
        glColor3f(1.0, 1.0, 0.0);
    }
    else{
        glLineWidth(1.0);
        glColor3f(0.5, 0.5, 0.5);
    }

    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x, y + 1);
    glEnd();
}

void drawFood(){
    if(food){
        random(foodX, foodY);
    }
    food = false;
    glColor3f(1.0, 0.0, 0.0);
    glRectf(foodX, foodY, foodX+1, foodY+1);
}

void drawSnake(){
    if(snakeDirection == UP){
        positionY++;
    }
    else if(snakeDirection == DOWN){
        positionY--;
    }
    else if(snakeDirection == RIGHT){
        positionX++;
    }
    else if(snakeDirection == LEFT){
        positionX--;
    }
    glRectd(positionX, positionY, positionX + 1, positionY + 1);
    if(positionX == gridX-1 || positionX == 0 || positionY==0 || positionY==gridY-1){
        gameOver = true;
    }

    if(positionX==foodX && positionY==foodY){
        food = true;
    }
}

void random(int &x, int &y){
    int max_X = gridX - 2;
    int max_Y = gridY - 2;
    int min = 1;
    srand(time(NULL));
    x = min + rand() % (max_X - min);
    y = min + rand() % (max_Y - min);
}


