#include "app.hpp"

void App::Start(){
    if (!glfwInit())
        return;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

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