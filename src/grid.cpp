#include "grid.hpp"
#include <GLFW/glfw3.h>


Grid::Grid(){
    clear();
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

    drawSelected();

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

void Grid::setSelected(int x, int y) {
    selectedX = x;
    selectedY = y;
}

void Grid::drawSelected() {
    if(selectedX == UNSELECTED)
        return;
    glBegin(GL_LINE_LOOP);

    glLineWidth(SEL_LINE_WIDTH);
    glColor3f(SELECTED_C);

    glVertex2f(cellSize * selectedX, cellSize * selectedY);
    glVertex2f(cellSize * selectedX + cellSize, cellSize * selectedY);
    glVertex2f(cellSize * selectedX + cellSize, cellSize * selectedY + cellSize);
    glVertex2f(cellSize * selectedX, cellSize * selectedY + cellSize);

    glEnd();
}

void Grid::select(){
    if(selectedX != UNSELECTED)
        grid[selectedX][selectedY] = !grid[selectedX][selectedY];
}

GRID_TYPE(int) Grid::countNeighs(){
    GRID_TYPE(int) neigs;
    for(int i = 0; i < GRID_W; ++i)
        neigs[i].fill(0);

    for(int x = 0; x < GRID_W; ++x) {
        for(int y = 0; y < GRID_H; ++y) {
            if(!grid[x][y]) {
                continue;
            }

            if(x > 0){
                ++neigs[x - 1][y];
                if(y > 0)
                    ++neigs[x - 1][y - 1];
                if(y < GRID_H - 1)
                    ++neigs[x - 1][y + 1];
            }
            if(x < GRID_W - 1){
                ++neigs[x + 1][y];
                if(y > 0)
                    ++neigs[x + 1][y - 1];
                if(y < GRID_H - 1)
                    ++neigs[x + 1][y + 1];
            }
            if(y > 0)
                ++neigs[x][y - 1];
            if(y < GRID_H - 1)
                ++neigs[x][y + 1];
        }
    }
    return neigs;
}

bool Grid::cycle(){
    selectedX = UNSELECTED;
    selectedY = UNSELECTED;
    auto neigs = countNeighs();
    for(int x = 0; x < GRID_W; ++x){
        for(int y = 0; y < GRID_H; ++y){
            if(grid[x][y]){
                if(neigs[x][y] < 2 || neigs[x][y] > 3)
                    grid[x][y] = false;
            }
            else
                if(neigs[x][y] == 3)
                    grid[x][y] = true;

        }
    }
    return true;
}

void Grid::clear(){
    for(int i = 0; i < GRID_W; ++i) {
        grid[i].fill(0);
    }
}