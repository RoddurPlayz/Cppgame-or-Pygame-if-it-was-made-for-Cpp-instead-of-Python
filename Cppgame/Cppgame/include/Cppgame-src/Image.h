#pragma once

#include <iostream>
#include <array>

#include "../SDL2-src/SDL.h"
#include "../SDL2-src/SDL_image.h"

#include "Math.h"
#include "Rect.h"


struct IMAGE
{
    SDL_Surface* image_surface;
    SDL_Texture* image_texture;
    SDL_Window* display;
    SDL_Renderer* renderer;

    VECTOR2 get_size();
    RECT get_rect(const std::array<float, 2>& topleft);
};
