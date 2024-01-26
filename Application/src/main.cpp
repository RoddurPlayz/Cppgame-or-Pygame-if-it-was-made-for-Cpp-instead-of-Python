#include <iostream>


#include <Cppgame-src/Cppgame.h>


class Super_Extras : public cppgame::extra::Extras
{
public:
    void on_quit()
    {

    }
};


class Player : public cppgame::sprite::Sprite
{
public:
    Player()
    {
        this->Sprite::image = cppgame::image::load("textures/test.png");
        this->Sprite::rect = cppgame::Rect({ 0, 0 });
    }


    void update()
    {
        std::cout << "X: " << this->Sprite::rect.rect.x << ", " << "Y: " << this->Sprite::rect.rect.y << "\r";
    }
};


int main(int argc, char* argv[])
{
    cppgame::init();
    cppgame::extra::set_extra_class(new Super_Extras);

    DISPLAY WIN = cppgame::display::set_mode({ 800, 600 }, 0, 0);

    cppgame::display::set_caption("TEST");

    Player* player = new Player();
    cppgame::sprite::Group group = cppgame::sprite::Group({player});

    CLOCK clock = cppgame::time::clock();

    while (true)
    {
        // std::cout << clock.tick(60) / 1000.0 << "\r";
        clock.tick(60);

        WIN.fill({ 255, 255, 255, 255 });

        for (SDL_Event event; cppgame::event::get(event);)
        {
            if (event.type == SDL_QUIT)
            {
                cppgame::quit();
                return 0;
            }
        }

        group.draw(WIN);

        cppgame::display::flip();
    }

    return 0;
}
