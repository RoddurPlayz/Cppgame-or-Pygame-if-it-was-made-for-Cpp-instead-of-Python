#include "Display.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Math.hpp"
#include "Rect.hpp"


void DISPLAY::fill(VECTOR4 rgba)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rgba.x, rgba.y, rgba.z, rgba.w);
}


void DISPLAY::blit(IMAGE& image, VECTOR2 position)
{
    RECT img_rect = image.get_rect(position);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = img_rect.rect.w;
    src.h = img_rect.rect.h;

    SDL_Rect dst;
    dst.x = img_rect.rect.x;
    dst.y = img_rect.rect.y;
    dst.w = img_rect.rect.w;
    dst.h = img_rect.rect.h;

    SDL_RenderCopy(renderer, image.image_texture, &src, &dst);
}
