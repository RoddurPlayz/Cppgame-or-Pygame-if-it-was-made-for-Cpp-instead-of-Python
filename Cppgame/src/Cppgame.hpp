#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.hpp"
#include "Image.hpp"
#include "Math.hpp"


static SDL_Window* DISPLAY;
static SDL_Renderer* RENDERER;


namespace cppgame
{
    int init();


    namespace display
    {
        Display set_mode(Vector2 size);

        void set_caption(const char* title);
        void set_icon(Image image);

        void flip();
    }


    namespace image
    {
        Image load(const char* file);
    }


    namespace math
    {
        Vector2 Vec2(float x, float y);
        Vector4 Vec4(float x, float y, float z, float w);
    }


    void quit();
}