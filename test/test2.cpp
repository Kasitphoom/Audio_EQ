#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <portaudio.h>

#define SDL_MAIN_HANDLED

const int SAMPLE_RATE = 44100;
const int BUFFER_SIZE = 1024;
const int NUM_CHANNELS = 2;

// Global variables
SDL_Window* window;
SDL_Renderer* renderer;

// Equalizer parameters
const int NUM_BANDS = 10;
const double GAIN_RANGE = 12.0;

double bandGains[NUM_BANDS] = { 0.0 };
double bandFrequencies[NUM_BANDS] = { 60, 170, 310, 600, 1000, 3000, 6000, 12000, 14000, 16000 };

// PortAudio callback function
int paCallback(const void* /*inputBuffer*/, void* outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* /*timeInfo*/,
               PaStreamCallbackFlags /*statusFlags*/,
               void* /*userData*/) {
    float* out = static_cast<float*>(outputBuffer);

    for (unsigned int i = 0; i < framesPerBuffer; i++) {
        double leftSample = 0.0;
        double rightSample = 0.0;

        // Apply equalizer filters
        for (int band = 0; band < NUM_BANDS; band++) {
            double frequency = bandFrequencies[band];
            double gain = bandGains[band];

            double w0 = 2.0 * M_PI * frequency / SAMPLE_RATE;
            double alpha = sin(w0) / 2.0;
            double b0 = 1.0 + alpha * gain;

            double inputSample = *out;

            leftSample += b0 * inputSample;
            rightSample += b0 * inputSample;

            out += NUM_CHANNELS;
        }

        *out = static_cast<float>(leftSample);   // Left channel
        out++;
        *out = static_cast<float>(rightSample);  // Right channel
        out++;
    }

    return paContinue;
}

// SDL event handling function
void handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(0);
        }
    }
}

// SDL rendering function
void render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    SDL_Rect rect;
    int bandWidth = SDL_GetWindowSurface(window)->w / NUM_BANDS;
    
    for (int band = 0; band < NUM_BANDS; band++) {
        rect.x = band * bandWidth;
        rect.y = SDL_GetWindowSurface(window)->h / 2;
        rect.w = bandWidth;
        rect.h = -bandGains[band] / GAIN_RANGE * rect.y;
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
    
    SDL_RenderPresent(renderer);
}

// SDL Mixer post-mix callback wrapper
void sdlMixerPostMixCallback(void* userData, Uint8* stream, int len) {
    // Convert audio data from Uint8 to float
    std::cout << "post mix [before]" << std::endl;
    float* floatStream = reinterpret_cast<float*>(stream);
    int floatLen = len / sizeof(float);

    for (int i = 0; i < floatLen; i++) {
        float sample = static_cast<float>(floatStream[i]) / 32768.0f;  // Normalize the sample to the range [-1, 1]
        floatStream[i] = sample;
    }
    std::cout << "post mix [after]" << std::endl;

    paCallback(floatStream, floatStream, floatLen, nullptr, 0, nullptr);
}

int WinMain(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Equalizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 400, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    // Initialize SDL Mixer
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_OGG);
    Mix_OpenAudio(SAMPLE_RATE, MIX_DEFAULT_FORMAT, NUM_CHANNELS, BUFFER_SIZE);
    
    // Initialize PortAudio
    Pa_Initialize();
    
    // Set up PortAudio parameters
    PaStream* outputStream;
    
    Pa_OpenDefaultStream(&outputStream, 0, NUM_CHANNELS, paFloat32, SAMPLE_RATE, BUFFER_SIZE, paCallback, nullptr);
    
    Pa_StartStream(outputStream);
    
    // Load and play the WAV file using SDL Mixer
    Mix_Chunk* music = Mix_LoadWAV("audio_cache/Jub.wav");
    int channel = Mix_PlayChannel(-1, music, -1);
    
    // Set the SDL Mixer post-mix callback
    Mix_SetPostMix(sdlMixerPostMixCallback, nullptr);
    
    // Main loop
    while (Mix_Playing(channel) != 0) {
        handleEvents();
        render();
        Pa_Sleep(10);
    }
    
    // Cleanup
    Mix_HaltChannel(-1);
    Mix_FreeChunk(music);
    Mix_CloseAudio();
    Mix_Quit();
    
    Pa_StopStream(outputStream);
    Pa_CloseStream(outputStream);
    Pa_Terminate();
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
