#include "game.h"
#include "graphics.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char**argv){
    int rows; 
    int columns;

    if (argc == 1){ // If no size provided, use default settings
        rows = 10;
        columns = 10;
    }
    else if (argc < 3 && argc != 1){
        // If game size not provided
        return 1;
    }
    else {
        rows = atoi(argv[1]);
        columns = atoi(argv[2]);
    }

    Game game(rows, columns);
    printf("Exiting.\n");
    return 0;
}

static void print_help(){
    std::cout << "Usage: ./main <ROWS> <COLUMNS>";
}
