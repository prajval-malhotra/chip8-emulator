#ifndef _graphics_h_
#define _graphics_h_ 1

#include <SDL2/SDL.h>
#include <iostream>

using std::cout;
using std::endl;

#define WIDTH 800
#define HEIGHT 600

typedef class Graphics {
public:

    SDL_Window *window;

    void init_graphics();
    void listen_for_input();
    void draw_graphics();
} Graphics;

#endif