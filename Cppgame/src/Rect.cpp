#include "Rect.h"


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


void RECT::move_ip(const float x, const float y)
{
    rect.x += x;
    rect.y += y;
}


bool RECT::collide_rect(const RECT& rect)
{
    if (SDL_HasIntersection(&this->rect, &rect.rect))
        return true;
    return false;
}
