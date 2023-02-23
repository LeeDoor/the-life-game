#pragma once
#include <GLFW/glfw3.h>

class App {
private:
    GLFWwindow* window;

    void Update();
public:
    void Start();
};