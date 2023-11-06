#include "Image.hpp"


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Rect.hpp"


Vector2 Image::get_size()
{
    SDL_Point size;
    if (SDL_QueryTexture(SDL_CreateTextureFromSurface(RENDERER, IMAGE), NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while querying image to get its size!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    Vector2 vector;
    vector.x = size.x;
    vector.y = size.y;

    return vector;
}


Rect Image::get_rect(Vector2 topleft)
{
    SDL_Point size;
    if (SDL_QueryTexture(SDL_CreateTextureFromSurface(RENDERER, IMAGE), NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while querying image to create a rect with it!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    Rect rect;
    rect.RECT.x = topleft.x;
    rect.RECT.y = topleft.y;
    rect.RECT.w = size.x;
    rect.RECT.h = size.x;

    return rect;
}
