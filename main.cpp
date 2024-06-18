#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int main(){
    //Game game;
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("Couldn't init SDL video.\n");
        return -1;
    }
    printf("SDL error says:\n\t-%s\n",SDL_GetError());
    Graphics graphics;
    bool running = true;
    SDL_GetError();
    while (running) {
    }
    
    printf("Exiting.\n");
    return 0;
}
