#include "Display.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.hpp"


void Display::set_caption(const char* title)
{
    SDL_SetWindowTitle(DISPLAY, title);
}


void Display::set_icon(Image image)
{
    SDL_SetWindowIcon(DISPLAY, image.IMAGE);
}