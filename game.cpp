#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <vector>
Game::Game(){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        printf("Couldn't init SDL video.\n");
    }
    printf("SDL error says:\n\t-%s\n",SDL_GetError());
    bool running = true;
    SDL_GetError();
    Grid grid(10,10);
    grid.switch_cell(0,1);
    grid.switch_cell(5,1);
    grid.switch_cell(4,7);
    
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            printf("cell[%d][%d] is: %d",
                    i,j,grid.cell_state(i,j));
        }
    }

    Graphics graphics(10,10,grid);
    unsigned int a =  SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    float delta = 0.0;
    while (running) {
        // FPS limiter
        a = SDL_GetTicks();
        delta=a-b;
        if(delta > 1000/1.0){
            b = a;
        }
    }
}
Game::~Game(){
    SDL_Quit();
}

Cell::Cell(){
    this->alive = 0;
}
Cell::~Cell(){}

int Cell::state(){
    return alive;
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
    if(row > this->grid.size() || column < this->grid[0].size()){
        return -1;
    }
    Cell cell = this->grid[row][column];
    return cell.state();
}
int Grid::switch_cell(int row, int column){
    if(row > this->grid.size() || column < this->grid[0].size()){
        printf("i like it here\n");
        return -1;
    }
    this->grid[row][column].switch_state();
    return 0;
}

Grid::~Grid(){}


