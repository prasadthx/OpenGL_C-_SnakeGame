//
// Created by prasad on 5/16/21.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <ctime>

int gridX, gridY;

bool food = true;

int snakeLength = 3;

int foodX, foodY;

short snakeDirection = RIGHT;

extern bool gameOver;
extern int score;

int positionX[60] = {20, 20, 20},
    positionY[60] = {20, 19, 18};

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
    for (int i = snakeLength - 1; i > 0; i--){
        positionX[i] = positionX[i - 1];
        positionY[i] = positionY[i - 1];
    }
    if(snakeDirection == UP){
        positionY[0]++;
    }
    else if(snakeDirection == DOWN){
        positionY[0]--;
    }
    else if(snakeDirection == RIGHT){
        positionX[0]++;
    }
    else if(snakeDirection == LEFT){
        positionX[0]--;
    }
    for(int i = 0; i < snakeLength; i++){
        if(i==0){
            glColor3f(0.0, 0.0, 1.0);
            glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
        }
        glColor3f(1.0, 0.0, 1.0);
        glRectd(positionX[i], positionY[i], positionX[i] + 1, positionY[i] + 1);
    }
    if(positionX[0] == gridX-1 || positionX[0] == 0 || positionY[0]==0 || positionY[0]==gridY-1){
        gameOver = true;
    }

    for(int j = 1; j < snakeLength ; j++){
        if(positionX[j] == positionX[0] && positionY[j] == positionY[0]){
            gameOver = true;
        }
    }

    if(positionX[0]==foodX && positionY[0]==foodY){
        snakeLength ++;
        score++;
        if(snakeLength > MAX){
            snakeLength = 3;
        }
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


