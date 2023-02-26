#include "app.hpp"
#include <iostream>

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    //std::cout << xpos << " " << ypos << std::endl;
}
static void window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void App::Start(){
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
    Update();

    glfwTerminate();
}

void App::Update(){
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(BG_C, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        grid.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}