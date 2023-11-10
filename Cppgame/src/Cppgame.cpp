#include "Cppgame.hpp"


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


int cppgame::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing everything!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return -1;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing PNG format!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return -1;
    }

    if (!Mix_Init(MIX_INIT_MP3 | MIX_INIT_OPUS | MIX_INIT_OGG))
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing MP3, OPUS and OGG format!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return -1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 6, 4096) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing audio!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";

        return -1;
    }

    return 0;
}


DISPLAY cppgame::display::set_mode(const std::array<float, 2>& size, Uint32 flags, int vsync)
{
    DISPLAY WIN;
    
    WIN.display = SDL_CreateWindow("Cppgame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size[0], size[1], flags);
    if (!WIN.display)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while initializing display!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    if (vsync) WIN.renderer = SDL_CreateRenderer(WIN.display, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    else WIN.renderer = SDL_CreateRenderer(WIN.display, -1, SDL_RENDERER_ACCELERATED);

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


void cppgame::display::set_icon(const IMAGE& image)
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


MUSIC cppgame::mixer::music::load(const char* file)
{
    MUSIC music;
    music.music = Mix_LoadMUS(file);
    return music;
}


void cppgame::mixer::music::set_volume(const float volume)
{
    Mix_VolumeMusic(volume);
}


void cppgame::mixer::music::pause()
{
    Mix_PauseMusic();
}


void cppgame::mixer::music::resume()
{
    Mix_ResumeMusic();
}


bool cppgame::mixer::music::get_state()
{
    return !Mix_PausedMusic();
}


RECT cppgame::Rect(const float left, const float top, const float width, const float height)
{
    RECT rect;
    rect.rect.x = left;
    rect.rect.y = top;
    rect.rect.w = width;
    rect.rect.h = height;

    return rect;
}


RECT cppgame::Rect(const std::array<float, 2>& left_top, const std::array<float, 2>& width_height)
{
    RECT rect;
    rect.rect.x = left_top[0];
    rect.rect.y = left_top[1];
    rect.rect.w = width_height[0];
    rect.rect.h = width_height[1];

    return rect;
}


RECT cppgame::Rect(const std::array<float, 4>& single_arg)
{
    RECT rect;
    rect.rect.x = single_arg[0];
    rect.rect.y = single_arg[1];
    rect.rect.w = single_arg[2];
    rect.rect.h = single_arg[3];

    return rect;
}


VECTOR2 cppgame::math::Vector2(const float x, const float y)
{
    VECTOR2 vec2;
    vec2.x = x;
    vec2.y = y;

    return vec2;
}


VECTOR4 cppgame::math::Vector4(const float x, const float y, const float z, const float w)
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

    IMG_Quit();
    Mix_Quit();
    Mix_HaltMusic();
}
