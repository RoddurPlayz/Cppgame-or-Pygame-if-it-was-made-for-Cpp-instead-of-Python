#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Math.hpp"


class Display
{
    public:
        SDL_Window* DISPLAY;
        SDL_Renderer* RENDERER;

        void fill(Vector4 rgba);
};
