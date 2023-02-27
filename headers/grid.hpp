#pragma once
#include "app_defines.hpp"
#include <array>
#define UNSELECTED -1

class Grid{
private:
    std::array<std::array<bool, GRID_H>, GRID_W> grid;
    float cellSize = 2.0f / (float)GRID_W;
    int selectedX = UNSELECTED, selectedY = UNSELECTED;

    void drawCol(int x);
    void drawCell(int x, int y);
    void drawSelected();
public:
    Grid();

    std::array<bool, GRID_H>& operator [](int id);

    void draw();
    void select();
    void setSelected(int x, int y);
    bool cycle();
};