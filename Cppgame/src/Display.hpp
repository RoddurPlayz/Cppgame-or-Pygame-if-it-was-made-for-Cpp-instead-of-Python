#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"


class Display
{
    public:
        SDL_Window* DISPLAY;
        SDL_Renderer* RENDERER;

        void set_caption(const char* title);
        void set_icon(Image image);
};
