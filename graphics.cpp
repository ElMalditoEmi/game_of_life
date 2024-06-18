#include "graphics.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#define W 500 // Window width
#define H 500 // Window height

Graphics::Graphics(){
    this->_window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,0);
    if(this->_window == NULL){
        printf("Failed to create a window.\n");
    }
    this->_renderer = SDL_CreateRenderer(this->_window,-1,0);
    if(this->_renderer== NULL){
        printf("Failed to create a renderer for the window.\n");
    }
    SDL_SetRenderDrawColor(this->_renderer,0,100,0,255);
    SDL_RenderClear(this->_renderer);
    SDL_RenderPresent(this->_renderer);
}

Graphics::~Graphics(){}
