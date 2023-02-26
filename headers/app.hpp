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

    static void Update();
public:
    static void Start();
    static void onMouseHover(int x, int y);
};