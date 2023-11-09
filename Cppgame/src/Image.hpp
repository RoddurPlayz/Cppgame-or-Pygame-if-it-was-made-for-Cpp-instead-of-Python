#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


struct IMAGE
{
    public:
        SDL_Surface* image_surface;
        SDL_Texture* image_texture;
        SDL_Window* display;
        SDL_Renderer* renderer;

        VECTOR2 get_size();
        RECT get_rect(VECTOR2 topleft);
};
