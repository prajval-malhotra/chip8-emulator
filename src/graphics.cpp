#include "graphics.h"

void Graphics::init_graphics() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Event window_event;

    if(window == NULL) {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
    }
}

void Graphics::listen_for_input() {
    SDL_Event Event;

    while (true) {
        SDL_PollEvent(&Event);
        
        if(SDL_PollEvent(&Event)) {
            if(Event.type == SDL_QUIT) {
                break;
            }
        }

        if (Event.type == SDL_KEYDOWN) {
            if (Event.key.keysym.sym == SDLK_UP) {
            // Up Arrow
                cout << "Up\n";
            } if (Event.key.keysym.sym == SDLK_DOWN) {
                cout << "Down\n";
            // Down Arrow
            } if (Event.key.keysym.sym == SDLK_LEFT) {
                cout << "Left\n";
            // Left Arrow
            } if (Event.key.keysym.sym == SDLK_RIGHT) {
                cout << "Right\n";
            // Right Arrow
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}