#include "Music.hpp"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL.h"
#include <iostream>

void Music::InitMusic(){
    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) < 0) {
        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        return;
    }

    this->current_path = this->all_path[0];
}

void Music::playMusic(){
    Mix_Chunk* music = Mix_LoadWAV(this->current_path);
    if (music == NULL) {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }

    int channel;

    channel = Mix_PlayChannel(-1, music, 0);
    if(channel == -1){
        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
    }

    while(Mix_Playing(channel) != 0){
        SDL_Delay(100);
    }

    Mix_FreeChunk(music);
}

void Music::pauseMusic(){
    Mix_Pause(-1);
}

void Music::resumeMusic(){
    Mix_Resume(-1);
}

void Music::stopMusic(){
    Mix_HaltChannel(-1);
}

void Music::setVolume(int volume){
    Mix_Volume(-1, volume);
}

void Music::Next(){
    this->music_index++;
    if(this->music_index >= this->all_path.size()){
        this->music_index = 0;
    }
    this->current_path = this->all_path[this->music_index];
}

void Music::Previous(){
    this->music_index--;
    if(this->music_index < 0){
        this->music_index = this->all_path.size() - 1;
    }
    this->current_path = this->all_path[this->music_index];
}

void Music::QuitMusic(){
    Mix_CloseAudio();
    SDL_Quit();
    Mix_Quit();
}

void Music::setPath(std::string path){
    this->all_path.push_back(const_cast<char*>(path.c_str()));
}

void Music::calculateAudioLength(Mix_Chunk* music, int& minutes, int& seconds, double& totalSeconds){
    int bitPerSample = 8; // Default bit-per-sample value (assuming 8-bit)

    // Get the audio format information
    SDL_AudioFormat format = 0;
    int channels = 0;
    int frequency = 0;
    if (Mix_QuerySpec(&frequency, &format, &channels) == 0) {
        // Failed to get audio format information, use default values
        std::cout << "Failed to get audio format information. Using default values." << std::endl;
    } else {
        bitPerSample = SDL_AUDIO_BITSIZE(format);
    }

    // Calculate the audio length
    Uint32 audioLength = music->alen;
    totalSeconds = static_cast<double>(audioLength) / (channels * bitPerSample / 8 * frequency);

    // Calculate the minutes and seconds
    minutes = static_cast<int>(totalSeconds) / 60;
    seconds = static_cast<int>(totalSeconds) % 60;
}

void Music::playMusic(std::thread& thread){
    thread = std::thread([this](){
        playMusic();
    });
}