#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "AudioFile.hpp"
#include "AudioFile.cpp"
#include "Music.hpp"
#include "Music.cpp"
#include <iostream>


double map(double value, double min1, double max1, double min2, double max2) {
    return min2 + (max2 - min2) * ((value - min1) / (max1 - min1));
}

int main(int arc, char* argv[]) {
    AudioFile* audioCache;
    audioCache = new AudioFileCache();

    Music* music;
    music = new Music(audioCache->getFilesFullPath());
    
    music->InitMusic();

    music->playMusic();

    music->QuitMusic();

    return 0;
}