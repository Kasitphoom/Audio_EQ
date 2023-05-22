#include "SDL2/SDL.h"
#include <iostream>

#define SDL_MAIN_HANDLED
#define MUS_PATH "../10000hrs.wav"

void audio_callback(void *userdata, Uint8 *stream, int len);

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

int WinMain(int argc, char* argv[]) {
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

    if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL ){
        std::cout << SDL_GetBasePath() << std::endl;
        std::cout << "Couldn't load " << MUS_PATH << ": " << SDL_GetError() << std::endl;
	    return 1;
	}

    wav_spec.callback = audio_callback;
    wav_spec.userdata = NULL;

    audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length
    // set our global static variables
	audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length

    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
	    std::cout << "Couldn't open audio: " << SDL_GetError() << std::endl;
	    exit(-1);
	}

    SDL_PauseAudio(0);

    while ( audio_len > 0 ) {
		SDL_Delay(100); 
	}

    // shut everything down
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);

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