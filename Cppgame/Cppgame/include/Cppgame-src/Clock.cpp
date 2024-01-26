#include "Clock.h"


#include "../SDL2-src/SDL.h"


long CLOCK::tick(double FPS)
{
    double current_tick_time = SDL_GetTicks();
    long raw_dt = current_tick_time - last_tick_time;
    dt = raw_dt / 1000;
    last_tick_time = current_tick_time;
    if (dt < 1000 / FPS)
    {
        SDL_Delay(1000 / FPS - dt);
    }

    return raw_dt;
}
