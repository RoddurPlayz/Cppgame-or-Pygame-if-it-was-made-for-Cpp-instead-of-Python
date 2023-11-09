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


DISPLAY cppgame::display::set_mode(VECTOR2 size, Uint32 flags)
{
    DISPLAY WIN;
    
    WIN.display = SDL_CreateWindow("Cppgame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.x, size.y, flags);
    if (!WIN.display)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing display!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    WIN.renderer = SDL_CreateRenderer(WIN.display, -1, SDL_RENDERER_ACCELERATED);

    Display = WIN.display;
    Renderer = WIN.renderer;
    Window = WIN;

    return WIN;
}


DISPLAY& cppgame::display::get_surface()
{
    return Window;
}


void cppgame::display::set_caption(const char* title)
{
    SDL_SetWindowTitle(Display, title);
}


void cppgame::display::set_icon(IMAGE image)
{
    SDL_SetWindowIcon(Display, image.image_surface);
}


void cppgame::display::flip()
{
    SDL_RenderPresent(Renderer);
}


IMAGE cppgame::image::load(const char* file)
{
    IMAGE image;
    image.display = Display;
    image.renderer = Renderer;
    image.image_surface = IMG_Load(file);
    image.image_texture = IMG_LoadTexture(Renderer, file);

    if (!image.image_surface || !image.image_texture)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while loading an image from directory \"" << file << "\"!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    return image;
}


VECTOR2 cppgame::math::Vector2(float x, float y)
{
    VECTOR2 vec2;
    vec2.x = x;
    vec2.y = y;

    return vec2;
}


VECTOR4 cppgame::math::Vector4(float x, float y, float z, float w)
{
    VECTOR4 vec4;
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


CLOCK cppgame::time::clock()
{
    CLOCK clock;

    return clock;
}


void cppgame::quit()
{
    SDL_DestroyWindow(Display);
    SDL_Quit();
}
