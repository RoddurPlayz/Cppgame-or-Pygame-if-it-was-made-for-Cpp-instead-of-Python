#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.hpp"
#include "Image.hpp"
#include "Math.hpp"
#include "Clock.hpp"


static SDL_Window* Display;
static SDL_Renderer* Renderer;
static DISPLAY Window;


namespace cppgame
{
    int init();


    namespace display
    {
        DISPLAY set_mode(VECTOR2 size);
        DISPLAY& get_surface();

        void set_caption(const char* title);
        void set_icon(IMAGE image);

        void flip();
    }


    namespace image
    {
        IMAGE load(const char* file);
    }


    namespace math
    {
        VECTOR2 Vector2(float x, float y);
        VECTOR4 Vector4(float x, float y, float z, float w);
    }


    namespace event
    {
        int get(SDL_Event& event_variable);
    }


    namespace time
    {
        CLOCK clock();
    }


    void quit();
}