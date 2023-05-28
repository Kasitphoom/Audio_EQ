#define SDL_MAIN_HANDLED
#include "mainwindow.h"

#include "SDL2/SDL.h"
#include <QApplication>
#include <thread>
#include <iostream>

int main(int argc, char *argv[])
{

    //    if (SDL_Init(SDL_INIT_AUDIO) < 0){
    //        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    //        return 1;
    //    }

    //    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) < 0) {
    //        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
    //        return 1;
    //    }

//    Mix_Chunk* music = Mix_LoadWAV(af->getFilesFullPath()[0]);
//    if (music == NULL) {
//        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
//        return 1;
//    }

//    int channel;

//    channel = Mix_PlayChannel(-1, music, 0);
//    if(channel == -1){
//        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
//    }

//    while(Mix_Playing(channel) != 0){
//        SDL_Delay(100);
//    }

//    Mix_FreeChunk(music);

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Vibin studio");
    w.show();
    return a.exec();
}

//void changeLan(MainWindow& main) {
//    //main.setT
//}
