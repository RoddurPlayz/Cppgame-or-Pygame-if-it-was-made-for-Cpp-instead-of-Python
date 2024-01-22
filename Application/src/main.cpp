#include <iostream>


#include <Cppgame-src/Cppgame.h>


int main(int argc, char* argv[])
{
    cppgame::init();

    DISPLAY WIN = cppgame::display::set_mode({ 800, 600 }, 0, 0);

    cppgame::display::set_caption("TEST");

    CLOCK clock = cppgame::time::clock();

    while (true)
    {
        std::cout << clock.tick(60) * 0.001 << "\r";

        WIN.fill({ 255, 255, 255, 255 });

        for (SDL_Event event; cppgame::event::get(event);)
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
