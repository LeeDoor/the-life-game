

cmake_minimum_required(VERSION 3.22)

project(theLifeGame)

#add_definitions(-lglut -lGLU -lGL)
set(SOURCES src/main.cpp)
add_executable(test ${SOURCES})
target_link_libraries(test GL GLU glut glfw)