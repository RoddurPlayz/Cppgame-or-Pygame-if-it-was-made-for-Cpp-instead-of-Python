#include "Image.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


VECTOR2 IMAGE::get_size()
{
    SDL_Point size;
    if (SDL_QueryTexture(image_texture, NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while querying image to get its size!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    VECTOR2 vector;
    vector.x = size.x;
    vector.y = size.y;

    return vector;
}


RECT IMAGE::get_rect(VECTOR2 topleft)
{
    SDL_Point size;
    if (SDL_QueryTexture(image_texture, NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while querying image to create a rect with it!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    RECT rect;
    rect.rect.x = topleft.x;
    rect.rect.y = topleft.y;
    rect.rect.w = size.x;
    rect.rect.h = size.x;

    return rect;
}
