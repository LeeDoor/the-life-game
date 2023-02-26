#pragma once
#include <GLFW/glfw3.h>
#include "app_defines.hpp"
#include "grid.hpp"
class App {
private:
    GLFWwindow* window;
    Grid grid;
    //void windowSizeCallback(GLFWwindow* window, int width, int height);
    void Update();
public:
    void Start();
};