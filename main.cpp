#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40

#define FPS 5

using namespace std;

extern short snakeDirection;
bool gameOver = false;
int score = 0;

void displayCallback();

void  reshapeCallback(int width, int height);

void timerCallback(int);

void keyboardCallback(int , int, int);

void initBackground(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLUMNS, ROWS);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SNAKE GAME");
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutTimerFunc(0, timerCallback, 0);
    glutSpecialFunc(keyboardCallback);
    initBackground();
    glutMainLoop();
    return 0;
}

void displayCallback(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if(gameOver){
        cout << "The score is: " << score <<endl;
        exit(0);
    }
}

void reshapeCallback(int width, int height){
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timerCallback(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timerCallback, 0);
}

void keyboardCallback(int key, int, int){
    switch (key) {
        case GLUT_KEY_UP:
            if(snakeDirection != DOWN){
                snakeDirection = UP;
            }
            break;
        case GLUT_KEY_DOWN:
            if (snakeDirection != UP){
                snakeDirection = DOWN;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (snakeDirection != LEFT){
                snakeDirection = RIGHT;
            }
            break;
        case GLUT_KEY_LEFT:
            if (snakeDirection != RIGHT){
                snakeDirection = LEFT;
            }
            break;
    }
}
