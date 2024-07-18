#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <vector>

#define ROWS 10
#define COLUMNS 10
Game::Game(){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        printf("Couldn't init SDL video.\n");
    }
    printf("SDL error says:\n\t-%s\n",SDL_GetError());
    bool running = true;
    SDL_GetError();
    Grid grid(ROWS,COLUMNS);
    grid.switch_cell(5,4);
    grid.switch_cell(5,5);
    grid.switch_cell(5,6);

    Graphics graphics(COLUMNS,ROWS,grid);    
    unsigned int a =  SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    float delta = 0.0;

    SDL_Event event;

    while (running) {
        SDL_PollEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                running = false;
                break;
        }
        // FPS limiter
        a = SDL_GetTicks();
        delta=a-b;
        if(delta > 1000/1.0){
            Update(grid, graphics);
            b = a;
        }
    }
}

/*Update()
 * Writes the self.grid with the corresponding next step in the simu
 * According to:
 * 1. If one live cell has 1 or less neighbors dies.
 * 2. If one live cell has 4 or more neighbors dies.
 * 3. If a live cell has 2 or 3 neighbors remains alive.
 * 4. Any dead cell with exactly 3 neighbors will became alive.
 */
void Game::Update(Grid grid, Graphics graphics)
{
    std::vector<std::vector<int>> should_switch; // Lists the pair of coordinates of which cells should change
    // For every cell in the grid we evaluate:
    for (int i = 0; i < grid.size() ; i++){
        for (int j = 0; j < grid.size(); j++){
            int actual_state = grid.cell_state(i,j);
            int neighbors = count_alive_neighbors(grid,i,j);

            int new_state = should_live_die(actual_state, neighbors);
            if (new_state != actual_state)
            {
                std::vector<int> pair;
                pair.push_back(i);
                pair.push_back(j);

                should_switch.push_back(pair);
            }
        }
    }
    for (int i = 0 ; i < should_switch.size() ; i++){
        grid.switch_cell(should_switch[i][0],should_switch[i][1]);
    }
    graphics.flushFrame(grid);
}

int Game::should_live_die(int actual_state, int neighbors)
{
    bool was_alive = actual_state == 1? true : false;
    if (was_alive){ 
        if (neighbors < 2) { return 0; }       // 1
        else if (neighbors >= 4) {return 0;}   // 2
        else {return 1;}                       // 3
    }
    else if (!was_alive)
    {
        if(neighbors == 3){ return 1;}
        else {return 0;}
    }
    return -1; // This should never be reached
}

int Game::count_alive_neighbors(Grid grid, int row, int column ){
    int count = 0;
    // grid.cell_state() returns -1 if arguments are out of bounds

    // Check the left (previous column)
    count = (grid.cell_state(row-1,column-1) == 1)? count + 1 : count;
    count = (grid.cell_state(row,column-1) == 1)? count + 1 : count;
    count = (grid.cell_state(row+1,column-1) == 1)? count + 1 : count;

    // Check above and bellow (same column)
    count = (grid.cell_state(row-1,column) == 1)? count + 1 : count;
    count = (grid.cell_state(row+1,column) == 1)? count + 1 : count;

    // Check the right (next column)
    count = (grid.cell_state(row-1,column+1) == 1)? count + 1 : count;
    count = (grid.cell_state(row,column+1) == 1)? count + 1 : count;
    count = (grid.cell_state(row+1,column+1) == 1)? count + 1 : count;

    return count;
}


Game::~Game(){
    SDL_Quit();
}

Cell::Cell(){
    this->alive = 0;
}
Cell::~Cell(){}

int Cell::state(){
    return this->alive;
}
void Cell::switch_state(){
    if (this->alive) {
        this->alive = 0;
    }
    else {
        this->alive = 1;
    }
}
Grid::Grid(int rows, int columns){
    
    // Intialize each cell
    for (int i = 0 ; i < rows; i++){
        std::vector<Cell> row;
        for (int j = 0; j < columns; j++){
            Cell new_cell = Cell();
            row.push_back(new_cell);
        }
        this->grid.push_back(row);
    }
}
int Grid::cell_state(int row, int column){
    if(row >= this->grid.size() || column >= this->grid[0].size() || row < 0 || column < 0){
        return -1;
    }
    Cell cell = this->grid[row][column];
    return cell.state();
}
int Grid::switch_cell(int row, int column){
    if(row > this->grid.size() || column > this->grid[0].size()){
        return -1;
    }
    this->grid[row][column].switch_state();
    return 0;
}

int Grid::size(){
    return this->grid.size();
}

Grid::~Grid(){}


