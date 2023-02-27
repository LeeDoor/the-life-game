/*-----sizes-----*/
#define WINDOW_W 1000 // window width in pixels
#define WINDOW_H 1000 // window height in pixels
#define GRID_W 50 // grid width in cells
#define GRID_H 50 // grid height in cells
#define SEL_LINE_WIDTH 5.0f // width of selected cell border

/*-----colors-----*/
#define BG_C 0.70196f, 1.00000f, 0.70196f // background color
#define CELL_C_DEAD 0.90196f, 1.00000f, 0.90196f // dead cell color
#define CELL_C_ALIVE 0.00000f, 0.60000f, 0.00000f // alive cell color
#define SELECTED_C 1.00000f, 0.60000f, 0.73333f //selected cell border color

/*-----timings-----*/
#define GAME_TICK 0.5f // update time of game in seconds

/*-----grid-----*/
#define UNSELECTED -1 // int of unselected grid
#define GRID_TYPE(x) std::array<std::array<x, GRID_H>, GRID_W> //type of grid