#include "graphics.h"
#include <SDL2/SDL.h>
#define W 500
#define H 500

Graphics::Graphics(){
    SDL_CreateWindowAndRenderer(W,H,0,
                                &this->_window,
                                &this->_renderer
                                );
}

Graphics::~Graphics(){}
