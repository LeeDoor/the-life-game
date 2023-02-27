# the-life-game
the life game project. game logic created on C++, gui drawed with GLFW, build with CMake. 

to build just create ./build directory, move there and build with cmake:
```
mkdir build
cd build 
cmake ..
make
```
hope you understand that you need cmake for this :)
also glfw required, on linux:
```
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
```
these lines copied from stackoverflow so i dont really know about second line but who cares

# controls
controls are simple: select with **left mouse button**, to start or stop game press **space**, to clear all press **C** button.

# size of grid
to change the size of grid, colors or update tickrate, see *app_defines.hpp* file in headers folder. dont forget to rebuild after changes.
have fun!
