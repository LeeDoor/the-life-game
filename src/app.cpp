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
        App::drawOnGrid();
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
        App::changeGameMode();
    if (key == GLFW_KEY_C && action == GLFW_RELEASE)
        App::clearGrid();
}

GLFWwindow* App::window;
Grid App::grid;
GameStates App::gameState = GameStates::Draw;
double App::startCycle = 0.0;

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
    glfwSetKeyCallback(window, key_callback);
    update();

    glfwTerminate();
}

void App::update(){
    double now, delta, accumulator, lastTime = 0.0;
    while (!glfwWindowShouldClose(window))
    { 

        glClearColor(BG_C, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        grid.draw();
        if(gameState == GameStates::Evolution){
            now = glfwGetTime() - startCycle;
            delta = now - lastTime;
            lastTime = now;
            accumulator += delta;
            if(accumulator >= GAME_TICK){
                grid.cycle();
                accumulator -= GAME_TICK;
            }
        }
        else{
            lastTime = 0.0;
        }
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

void App::drawOnGrid(){
    if(gameState == GameStates::Draw){
        grid.select();
    }
}

void App::changeGameMode(){
    if(gameState == GameStates::Draw)
        gameState = GameStates::Evolution;
    else
        gameState = GameStates::Draw;
    startCycle = glfwGetTime();
}

void App::clearGrid(){
    grid.clear();
    gameState = GameStates::Draw;
}