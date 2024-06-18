#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>

Game::Game(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("Couldn't init SDL video.\n");
    }
    printf("SDL error says:\n\t-%s\n",SDL_GetError());
    Graphics graphics;
    bool running = true;
    SDL_GetError();
    while (running) {
    }
}
Game::~Game(){
    SDL_Quit();
}
