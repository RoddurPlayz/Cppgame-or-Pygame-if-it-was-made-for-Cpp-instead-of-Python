#include "Display.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Math.hpp"
#include "Rect.hpp"


void Display::fill(Vector4 rgba)
{
    SDL_RenderClear(RENDERER);
    SDL_SetRenderDrawColor(RENDERER, rgba.x, rgba.y, rgba.z, rgba.w);
}


void Display::blit(Image& image, Vector2 position)
{
    Rect img_rect = image.get_rect(position);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = img_rect.RECT.w;
    src.h = img_rect.RECT.h;

    SDL_Rect dst;
    dst.x = img_rect.RECT.x;
    dst.y = img_rect.RECT.y;
    dst.w = img_rect.RECT.w;
    dst.h = img_rect.RECT.h;

    SDL_RenderCopy(RENDERER, image.IMAGE_TEXTURE, &src, &dst);
}
