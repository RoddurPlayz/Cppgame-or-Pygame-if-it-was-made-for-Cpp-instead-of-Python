#pragma once


#include "../SDL2-src/SDL.h"
#include "../SDL2-src/SDL_image.h"


struct RECT
{
    SDL_Rect rect;

    void move_ip(const float x, const float y);

    bool collide_rect(const RECT& rect);
};
