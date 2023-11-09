#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct RECT
{
    SDL_Rect rect;

    void move_ip(float x, float y);

    bool collide_rect(RECT& rect);
};
