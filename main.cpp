#include <SDL2/SDL.h>

#include "Cppgame/src/Cppgame.hpp"


int main(int argc, char *argv[])
{
    Cppgame::init();

    Display WIN = Cppgame::set_mode(Cppgame::Vec2(800, 600));

    return 0;
}
