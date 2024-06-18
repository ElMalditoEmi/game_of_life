#include "graphics.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"
#define W 600 // Window width
#define H 500 // Window height

Graphics::Graphics(int rows, int columns, Grid grid){
    this->rows = rows;
    this->columns = columns;
    this->_window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,0);
    if(this->_window == NULL){
        printf("Failed to create a window.\n");
    }
    this->_renderer = SDL_CreateRenderer(this->_window,-1,0);
    if(this->_renderer== NULL){
        printf("Failed to create a renderer for the window.\n");
    }
    // Draws the empty background.
    SDL_SetRenderDrawColor(this->_renderer,255,255,255,255);
    SDL_RenderClear(this->_renderer);

    // Draws an empty grid
    SDL_SetRenderDrawColor(this->_renderer,5,5,2,255);
    int cell_width = W/rows;
    int cell_height = H/columns;
    for (int i = 0 ; i < rows ; i++){
        for (int  j = 0; j < columns; j++){
            SDL_Rect rect;
            rect.w=cell_width;
            rect.h=cell_height;
            rect.x=i*(cell_width);
            rect.y=j*(cell_height);
            SDL_RenderDrawRect(this->_renderer, &rect);
            if(grid.cell_state(i,j) == 1){
                SDL_RenderFillRect(
                        this->_renderer, &rect);
                printf("AAAAAAAAAAAAAAAAA\n\n\n");
            }
        }
    }
    SDL_RenderPresent(this->_renderer);
}
void Graphics::updateCell(int row, int column,
                            int new_state){
    // Determine cell's position
    int cell_width = W/this->rows;
    int cell_height = H/this->columns;
    SDL_Rect rect;
    rect.w=cell_width;
    rect.h=cell_height;
    rect.x=row*(cell_width);
    rect.y=column*(cell_height);

    // repaint/clean cell using background color
    SDL_SetRenderDrawColor(this->_renderer,
            255,255,255,255);
    SDL_RenderFillRect(this->_renderer, &rect);

    //Update cell
    SDL_SetRenderDrawColor(this->_renderer,5,5,2,255);
    if(new_state == 0){
        SDL_RenderDrawRect(this->_renderer, &rect);
    }
    else if (new_state == 1){
        SDL_RenderFillRect(this->_renderer, &rect);
    }
}

Graphics::~Graphics(){}
