#include <iostream>
#include <SDL2/SDL.h>
#include "system_data.h"
#include "graphics.h"

using std::cout;
using std::endl;

const int width = 800, height = 600;

int main(int argc, char* argv[]) {

    SystemData system_data;
    Graphics graphics;
    
    graphics.init_graphics();
    graphics.listen_for_input();
    
    return 0;

}