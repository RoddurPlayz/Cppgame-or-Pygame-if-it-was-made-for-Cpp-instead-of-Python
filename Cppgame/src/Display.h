#pragma once


#include <array>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Image.h"
#include "Math.h"
#include "Rect.h"


struct DISPLAY
{
    SDL_Window* display;
    SDL_Renderer* renderer;

    void fill(const std::array<float, 4>& rgba);
    void blit(IMAGE& image, const std::array<float, 2>& position);
    void blit(IMAGE& image, RECT& rect);
};
