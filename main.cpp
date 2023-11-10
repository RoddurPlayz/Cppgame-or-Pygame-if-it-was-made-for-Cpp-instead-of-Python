#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include "Cppgame/src/Cppgame.hpp"


class Player
{
    public:
        void draw(DISPLAY& display)
        {
            display.blit(image, {0, 0});
        }
    
    private:
        IMAGE image = cppgame::image::load("textures/test.png");
        RECT rect = image.get_rect({0, 0});
};


int main(int argc, char *argv[])
{
    cppgame::init();

    DISPLAY WIN = cppgame::display::set_mode({800, 600}, 0, 0);
    
    IMAGE img = cppgame::image::load("textures/test.png");

    cppgame::display::set_caption("TEST");
    cppgame::display::set_icon(img);

    CLOCK clock = cppgame::time::clock();

    Player player;

    while (true)
    {
        clock.tick(60);

        WIN.fill({255, 255, 255, 255});
        
        for (SDL_Event event; cppgame::event::get(event);)
        {
            if (event.type == SDL_QUIT)
            {
                cppgame::quit();
                return 0;
            }
        }

        player.draw(WIN);

        cppgame::display::flip();
    }

    return 0;
}
