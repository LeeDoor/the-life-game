#pragma once
#include <GLFW/glfw3.h>
#include "app_defines.hpp"
#include "grid.hpp"
class App {
private:
    GLFWwindow* window;
    Grid grid;
    
    void Update();
public:
    void Start();
};