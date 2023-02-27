#include "app.hpp"
#include <iostream>

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    App::onMouseHover(xpos, ypos);
}
void window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        App::onMouseLMB();
}

GLFWwindow* App::window;
Grid App::grid;
GameStates App::gameState = GameStates::Draw;

void App::start(){
    if (!glfwInit())
        return;

    window = glfwCreateWindow(500, 500, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    update();

    glfwTerminate();
}

void App::update(){
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(BG_C, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        grid.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void App::onMouseHover(int x, int y){
    if(gameState == GameStates::Evolution)return;
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    
    int numX = x / (w / (float)GRID_W);
    int numY = GRID_H - y / (h / (float)GRID_H);

    grid.setSelected(numX, numY);
}

void App::onMouseLMB(){
    if(gameState == GameStates::Draw){
        grid.select();
    }
}