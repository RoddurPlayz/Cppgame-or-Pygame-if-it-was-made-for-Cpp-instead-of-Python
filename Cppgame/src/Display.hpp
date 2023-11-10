#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Math.hpp"
#include "Rect.hpp"


struct DISPLAY
{
    SDL_Window* display;
    SDL_Renderer* renderer;

    void fill(VECTOR4 rgba);
    void blit(IMAGE& image, VECTOR2 position);
};
