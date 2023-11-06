#include "Rect.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void Rect::move_ip(float x, float y)
{
    RECT.x += x;
    RECT.y += y;
}


bool Rect::collide_rect(Rect& rect)
{
    if (SDL_HasIntersection(&RECT, &rect.RECT))
        return true;
    return false;
}
