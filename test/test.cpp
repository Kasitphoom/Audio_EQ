#include "SDL2/SDL.h"
#define SDL_MAIN_HANDLED

void audio_callback(void *userdata, Uint8 *stream, int len);

int WinMain(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) return 1;
        
    static ui
    SDL_Window* window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
