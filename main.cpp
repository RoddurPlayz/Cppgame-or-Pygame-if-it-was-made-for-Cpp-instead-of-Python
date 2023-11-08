#include <iostream>

#include <SDL2/SDL.h>

#include "Cppgame/src/Cppgame.hpp"


int main(int argc, char *argv[])
{
    cppgame::init();

    Display WIN = cppgame::display::set_mode(cppgame::math::Vec2(800, 600));
    Clock clock = cppgame::time::clock();

    Image img = cppgame::image::load("textures/test.png");

    cppgame::display::set_caption("TEST");
    cppgame::display::set_icon(img);

    Vector2 pos = cppgame::math::Vec2(0, 0);

    SDL_Event event;

    while (true)
    {
        clock.tick(60);

        WIN.fill(cppgame::math::Vec4(255, 255, 255, 255));
        
        for (;cppgame::event::get(event);)
        {
            if (event.type == SDL_QUIT)
            {
                cppgame::quit();
                return 0;
            }
        }

        WIN.blit(img, pos);

        cppgame::display::flip();
    }

    return 0;
}
