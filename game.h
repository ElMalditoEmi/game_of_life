#ifndef GAME_H
#define GAME_H
#include <vector>
#include "graphics.h"

class Cell{
    public:
        Cell();
        ~Cell();
        //returns 1 if cell is alive, 0 otherwise.
        int state();
        // switches cell state between alive and death.
        void switch_state();
    private:
        int alive = 0;
};

class Grid{
    public:
        Grid(int rows, int columns);
        ~Grid();
        // Checks for cell state, returns 1 in case cell is alive, 0 otherwise.
        int cell_state(int row, int column);
        // Switches the cell state between alive and dead.
        int switch_cell(int row, int column);
        int size();
    private:
        std::vector<std::vector<Cell>> grid;
};
/*Game class
 * Holds the game logic.
 */
class Game{
    public:
        Game();
        ~Game();
        void Update();
        Grid* grid;
        Graphics* graphics;
    private:
        int count_alive_neighbors(Grid* grid, int row, int column);
        int should_live_die(int actual_state, int neighbors);
};


#endif
