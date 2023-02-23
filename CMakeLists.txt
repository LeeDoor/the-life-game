

cmake_minimum_required(VERSION 3.22)

project(theLifeGame)

set(SOURCES src/main.cpp src/app.cpp)
include_directories(headers)
add_executable(test ${SOURCES})
target_link_libraries(test GL GLU glut glfw)