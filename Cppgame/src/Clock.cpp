#include "Clock.hpp"


#include "SDL2/SDL.h"


double CLOCK::tick(double FPS)
{
    double current_tick_time = SDL_GetTicks();
    dt = (current_tick_time - last_tick_time) / 1000;
    last_tick_time = current_tick_time;
    if (dt < 1000 / FPS)
    {
        SDL_Delay(1000 / FPS - dt);
    }
    
    return dt * 1000;
}
