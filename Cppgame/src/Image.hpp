#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


struct Image
{
    public:
        SDL_Surface* IMAGE_SURFACE;
        SDL_Texture* IMAGE_TEXTURE;
        SDL_Window* DISPLAY;
        SDL_Renderer* RENDERER;

        Vector2 get_size();
        Rect get_rect(Vector2 topleft);
};
