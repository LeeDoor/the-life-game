#pragma once
#include "app_defines.hpp"
#include <array>

class Grid{
private:
    std::array<std::array<bool, GRID_H>, GRID_W> grid;
    float cellSize = 2.0f / (float)GRID_W;
    int selectedX = -1, selectedY = -1;

    void drawCol(int x);
    void drawCell(int x, int y);
    void drawSelected();
public:
    Grid();

    std::array<bool, GRID_H>& operator [](int id);

    void draw();
    void setSelected(int x, int y);
};