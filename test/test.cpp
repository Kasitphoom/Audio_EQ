#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "AudioFile.hpp"
#include "AudioFile.cpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>

namespace fs = std::filesystem;

#define SDL_MAIN_HANDLED

void audio_callback(void *userdata, Uint8 *stream, int len);

void calculateAudioLength(const SDL_AudioSpec& audioSpec, Uint32 audioLength, int& minutes, int& seconds, double& totalSeconds) {
    
    int bitPerSample = SDL_AUDIO_BITSIZE(audioSpec.format);
    
    totalSeconds = static_cast<double>(audioLength) / (static_cast<int>(audioSpec.channels) * bitPerSample / 8 * audioSpec.freq);

    // Calculate the minutes and seconds
    minutes = static_cast<int>(totalSeconds) / 60;
    seconds = static_cast<int>(totalSeconds) % 60;
}

double map(double value, double min1, double max1, double min2, double max2) {
    return min2 + (max2 - min2) * ((value - min1) / (max1 - min1));
}

double starttime(double input, double totalSeconds) {
    return map(input, 0, 100, 0, totalSeconds);
}

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

int WinMain(int argc, char* argv[]) {

    if(!fs::is_directory(FILE_CACHE_PATH)) {
        fs::create_directory(FILE_CACHE_PATH);
    }

    AudioFileCache audioCache;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Audio Player", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    static Uint32 wav_length; // length of our sample
	static Uint8 *wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec; // the specs of our piece of music

    for(auto& p: audioCache.getFilesFullPath()) {
        std::cout << p << std::endl;
    
        if( SDL_LoadWAV(p, &wav_spec, &wav_buffer, &wav_length) == NULL ){
            std::cout << SDL_GetBasePath() << std::endl;
            std::cout << "Couldn't load " << p << ": " << SDL_GetError() << std::endl;
            return 1;
        }

        int audioMinutes, audioSeconds;
        double TotalSeconds;
        calculateAudioLength(wav_spec, wav_length, audioMinutes, audioSeconds, TotalSeconds);
        std::cout << "Real Audio Length: " << audioMinutes << " minutes " << audioSeconds << " seconds" << std::endl;

        wav_spec.callback = audio_callback;
        wav_spec.userdata = NULL;

        

        Uint32 startPos = starttime(0, TotalSeconds) * wav_spec.freq * wav_spec.channels * SDL_AUDIO_BITSIZE(wav_spec.format) / 8;
        wav_buffer += startPos;
        wav_length -= startPos;

        audio_pos = wav_buffer; // copy sound buffer
        audio_len = wav_length; // copy file length
        // set our global static variables
        audio_pos = wav_buffer; // copy sound buffer
        audio_len = wav_length; // copy file length

        calculateAudioLength(wav_spec, wav_length, audioMinutes, audioSeconds, TotalSeconds);
        std::cout << "Play Audio Length: " << audioMinutes << " minutes " << audioSeconds << " seconds" << std::endl;

        if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
            std::cout << "Couldn't open audio: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        SDL_PauseAudio(0);

        while ( audio_len > 0 ) {
            SDL_Delay(100); 
        }

        SDL_CloseAudio();
	    SDL_FreeWAV(wav_buffer);
    }
    std::cout << "Finished playing audio" << std::endl;

    // shut everything down
	

    return 0;
}


void audio_callback(void *userdata, Uint8 *stream, int len) {
	
	if (audio_len == 0)
		return;

	len = ( len > audio_len ? audio_len : len );
	SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
	
	audio_pos += len;
	audio_len -= len;
}