#include <iostream>
#include <SDL2/SDL.h>
// #include "system_data.h"

using std::cout, std::endl;

const int width = 800, height = 600;

int main(int argc, char* argv[]) {

    // SystemData system_data;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    if(window == NULL) {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
    }

    SDL_Event window_event;

    while(true) {
        if(SDL_PollEvent(&window_event)) {
            if(SDL_QUIT == window_event.type) {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;

}