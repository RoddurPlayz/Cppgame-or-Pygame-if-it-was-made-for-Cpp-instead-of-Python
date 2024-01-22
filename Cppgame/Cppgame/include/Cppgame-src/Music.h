#pragma once


#include "../SDL2-src/SDL_mixer.h"


struct MUSIC
{
    Mix_Music* music;

    void play(const int loops);

    float get_volume();
};
