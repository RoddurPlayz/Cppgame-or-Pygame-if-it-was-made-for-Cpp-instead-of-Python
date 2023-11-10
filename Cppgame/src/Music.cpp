#include "Music.hpp"


#include <SDL2/SDL_mixer.h>


void MUSIC::play(int loops)
{
    Mix_PlayMusic(music, loops);
}


float MUSIC::get_volume()
{
    return Mix_GetMusicVolume(music);
}
