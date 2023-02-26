#include "grid.hpp"
#include <GLFW/glfw3.h>

Grid::Grid(){
    for(int i = 0; i < GRID_W; ++i) {
        grid[i].fill(i%2);
    }
}


std::array<bool, GRID_H>& Grid::operator [](int id){
    return grid[id];
}

void Grid::draw(){

    glPushMatrix();
    glTranslatef(-1.0f, -1.0f, 0.0f);

    glBegin(GL_QUADS);

    for(int x = 0; x < GRID_W; ++x){
        drawCol(x);
    }

    glEnd();
    glPopMatrix();
}
void Grid::drawCol(int x) {
    for(int y = 0; y < GRID_H; ++y) {
        drawCell(x, y);
    }
}
void Grid::drawCell(int x, int y) {
    //setting color to cell
    if(grid[x][y])
        glColor3f(CELL_C_ALIVE);
    else
        glColor3f(CELL_C_DEAD);
    glVertex2f(cellSize * x, cellSize * y);
    glVertex2f(cellSize * x + cellSize, cellSize * y);
    glVertex2f(cellSize * x + cellSize, cellSize * y + cellSize);
    glVertex2f(cellSize * x, cellSize * y + cellSize);
}