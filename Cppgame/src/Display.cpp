#include "Display.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Math.hpp"


void Display::fill(Vector4 rgba)
{
    SDL_RenderClear(RENDERER);
    SDL_SetRenderDrawColor(RENDERER, rgba.x, rgba.y, rgba.z, rgba.w);
}
