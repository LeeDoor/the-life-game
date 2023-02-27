#pragma once
#include <GLFW/glfw3.h>
#include "app_defines.hpp"
#include "grid.hpp"
#include "game_states.hpp"

class App {
private:
    static GLFWwindow* window;
    static Grid grid;
    static GameStates gameState;
    static double startCycle;

    static void update();
public:
    static void start();
    static void onMouseHover(int x, int y);
    static void drawOnGrid();
    static void changeGameMode();
};