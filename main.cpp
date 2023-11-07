#include <iostream>

#include <SDL2/SDL.h>

#include "Cppgame/src/Cppgame.hpp"


int main(int argc, char *argv[])
{
    cppgame::init();

    Display WIN = cppgame::display::set_mode(cppgame::math::Vec2(800, 600));

    cppgame::display::set_caption("TEST");
    cppgame::display::set_icon(cppgame::image::load("textures/test.png"));

    SDL_Event event;

    while (true)
    {
        WIN.fill(cppgame::math::Vec4(255, 255, 255, 255));
        
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                cppgame::quit();
                return 0;
            }
        }

        cppgame::display::flip();
    }

    return 0;
}
