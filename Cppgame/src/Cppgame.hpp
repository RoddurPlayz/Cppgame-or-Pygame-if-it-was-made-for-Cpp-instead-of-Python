#pragma once

#include <iostream>
#include <array>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Display.hpp"
#include "Image.hpp"
#include "Math.hpp"
#include "Clock.hpp"
#include "Music.hpp"


static SDL_Window* Display;
static SDL_Renderer* Renderer;
static DISPLAY Window;


namespace cppgame
{
    int init();


    namespace display
    {
        DISPLAY set_mode(const std::array<float, 2>& size, Uint32 flags, int vsync);
        DISPLAY& get_surface();

        void set_caption(const char* title);
        void set_icon(const IMAGE& image);

        void flip();
    }


    namespace image
    {
        IMAGE load(const char* file);
    }


    namespace mixer
    {
        namespace music
        {
            MUSIC load(const char* file);
            void set_volume(const float volume);

            void pause();
            void resume();

            bool get_state();
        }
    }

    RECT Rect(float left, float top, float width, float height);
    RECT Rect(const std::array<float, 2>& left_top, const std::array<float, 2>& width_height);
    RECT Rect(const std::array<float, 4>& single_arg);

    namespace math
    {
        VECTOR2 Vector2(const float x, const float y);
        VECTOR4 Vector4(const float x, const float y, const float z, const float w);
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