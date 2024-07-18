#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;
struct Grid;

class Graphics
{
    public:
        Graphics(int rows, int columns, Grid grid);
        ~Graphics();
        void updateCell(int row,
                int column, int new_state);
        void flushFrame(Grid grid);
    private:
        int rows;
        int columns;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
};

#endif
