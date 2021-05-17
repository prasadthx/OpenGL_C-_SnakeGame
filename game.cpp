//
// Created by prasad on 5/16/21.
//

#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

int gridX, gridY;

void unit(int, int);

int initGrid(int x, int y){
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
    glLineWidth(1.0);
    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 1, y);
        glVertex2f(x + 1, y + 1);
        glVertex2f(x, y + 1);
    glEnd();
}


