#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "AudioFile.hpp"
#include "AudioFile.cpp"
#include <iostream>

int main(int arc, char* argv[]) {
    AudioFileCache audioCache;
    
    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) < 0) {
        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_mixer initialization failed: %s", Mix_GetError());
        return 1;
    }

    Mix_Chunk* music = Mix_LoadWAV("audio_cache/10000hrs.wav");
    if (music == NULL) {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load music: %s", Mix_GetError());
        return 1;
    }

    int channel;

    channel = Mix_PlayChannel(-1, music, 0);
    if(channel == -1){
        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
    }

    while (Mix_Playing(channel) != 0) {
        std::cout << "Playing music" << std::endl;
        SDL_Delay(100);
    }

    Mix_FreeChunk(music);
    Mix_CloseAudio();
    SDL_Quit();
    Mix_Quit();

    return 0;
}