#include "Cppgame.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.hpp"
#include "Image.hpp"
#include "Math.hpp"
#include "Clock.hpp"


int cppgame::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing everything!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing PNG format!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return 1;
    }

    return 0;
}


Display cppgame::display::set_mode(Vector2 size)
{
    Display display;
    
    display.DISPLAY = SDL_CreateWindow("Cppgame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, 0);
    if (!display.DISPLAY)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing display!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    display.RENDERER = SDL_CreateRenderer(display.DISPLAY, -1, SDL_RENDERER_ACCELERATED);

    DISPLAY = display.DISPLAY;
    RENDERER = display.RENDERER;

    return display;
}


void cppgame::display::set_caption(const char* title)
{
    SDL_SetWindowTitle(DISPLAY, title);
}


void cppgame::display::set_icon(Image image)
{
    SDL_SetWindowIcon(DISPLAY, image.IMAGE_SURFACE);
}


void cppgame::display::flip()
{
    SDL_RenderPresent(RENDERER);
}


Image cppgame::image::load(const char* file)
{
    Image image;
    image.DISPLAY = DISPLAY;
    image.RENDERER = RENDERER;
    image.IMAGE_SURFACE = IMG_Load(file);
    image.IMAGE_TEXTURE = IMG_LoadTexture(RENDERER, file);

    if (!image.IMAGE_SURFACE || !image.IMAGE_TEXTURE)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while loading an image from directory \"" << file << "\"!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    return image;
}


Vector2 cppgame::math::Vec2(float x, float y)
{
    Vector2 vec2;
    vec2.x = x;
    vec2.y = y;

    return vec2;
}


Vector4 cppgame::math::Vec4(float x, float y, float z, float w)
{
    Vector4 vec4;
    vec4.x = x;
    vec4.y = y;
    vec4.z = z;
    vec4.w = w;

    return vec4;
}


int cppgame::event::get(SDL_Event& event_variable)
{
    return SDL_PollEvent(&event_variable);
}


Clock cppgame::time::clock()
{
    Clock clock;

    return clock;
}


void cppgame::quit()
{
    SDL_DestroyWindow(DISPLAY);
    SDL_Quit();
}
