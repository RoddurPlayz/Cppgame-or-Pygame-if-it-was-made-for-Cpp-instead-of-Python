#pragma once


#include "../SDL2-src/SDL.h"


struct CLOCK
{
    long tick(double FPS);

private:
    double FPS = 0.0f;
    double dt;
    double last_tick_time;
};

