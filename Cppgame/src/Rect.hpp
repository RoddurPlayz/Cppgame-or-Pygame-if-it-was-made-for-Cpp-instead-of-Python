#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct Rect
{
    SDL_Rect RECT;

    void move_ip(float x, float y);

    bool collide_rect(Rect& rect);
};
