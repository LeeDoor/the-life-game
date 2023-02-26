#pragma once
#include "app_defines.hpp"
#include <array>

class Grid{
private:
    std::array<std::array<bool, GRID_H>, GRID_W> grid;
    float cellSize = 2.0f / (float)GRID_W;

    void drawCol(int x);
    void drawCell(int x, int y);
public:

    Grid();

    std::array<bool, GRID_H>& operator [](int id);

    void draw();
};