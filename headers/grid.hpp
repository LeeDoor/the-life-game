#pragma once
#include "app_defines.hpp"
#include <array>

class Grid{
private:
    std::array<std::array<bool, GRID_H>, GRID_W> grid;
    float cellSize = 0.1;

    void drawCol(int x);
    void drawCell(int x, int y);
public:
    Grid();

    std::array<bool, GRID_H>& operator [](int id);

    void draw();
};