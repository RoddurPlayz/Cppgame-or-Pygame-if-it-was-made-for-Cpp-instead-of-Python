#include "Image.h"


#include <iostream>

#include "../SDL2-src/SDL.h"
#include "../SDL2-src/SDL_image.h"

#include "Math.h"
#include "Rect.h"


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


RECT IMAGE::get_rect(const std::array<float, 2>& topleft)
{
    SDL_Point size;
    if (SDL_QueryTexture(image_texture, NULL, NULL, &size.x, &size.y) < 0)
    {
        std::cout << "[Cppgame] Cppgame ran into an error while querying image to create a rect with it!" << "\n";
        std::cout << "[Cppgame Error] " << SDL_GetError() << "\n";
    }

    RECT rect;
    rect.rect.x = topleft[0];
    rect.rect.y = topleft[1];
    rect.rect.w = size.x;
    rect.rect.h = size.x;

    return rect;
}
