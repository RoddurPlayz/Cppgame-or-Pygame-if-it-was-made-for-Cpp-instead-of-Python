#include "Display.h"


#include <array>

#include "../SDL2-src/SDL.h"
#include "../SDL2-src/SDL_image.h"

#include "Image.h"
#include "Math.h"
#include "Rect.h"


void DISPLAY::fill(const std::array<float, 4>& rgba)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);
}


void DISPLAY::blit(IMAGE& image, const std::array<float, 2>& position)
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


void DISPLAY::blit(IMAGE& image, RECT& rect)
{
    RECT img_rect = image.get_rect({ (float)rect.rect.x, (float)rect.rect.y });

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = img_rect.rect.w;
    src.h = img_rect.rect.h;

    SDL_Rect dst;
    dst.x = rect.rect.x;
    dst.y = rect.rect.y;
    dst.w = img_rect.rect.w;
    dst.h = img_rect.rect.h;

    SDL_RenderCopy(renderer, image.image_texture, &src, &dst);
}
