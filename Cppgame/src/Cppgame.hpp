#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.hpp"
#include "Image.hpp"
#include "Math.hpp"


static SDL_Window* DISPLAY;
static SDL_Renderer* RENDERER;


namespace Cppgame
{
    int init();

    Display set_mode(Vector2 size);
    Image load_image(const char* file);

    Vector2 Vec2(float x, float y);
}