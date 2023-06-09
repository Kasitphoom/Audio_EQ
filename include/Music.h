#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <string>
#include <vector>
#include <thread>
#include "AudioFile.h"
#include "../SDL/x86_64-w64-mingw32/include/SDL2/SDL_mixer.h"

//QT_BEGIN_NAMESPACE
//namespace MUS {class Music;}
//QT_END_NAMESPACE
namespace MUS{
class Music {
    private:
        Mix_Chunk* music;

        std::vector<char*> all_path;

        char* current_path;

        std::string name;

        int minute;
        int second;
        int music_index;

        double totalSecond;

        void setPath(std::string path);
        void calculateAudioLength(Mix_Chunk* music, int& minutes, int& seconds, double& totalSeconds);
        void playMusicThread();

    public:
        Music(std::vector<char*> path) : all_path(path), minute(0), second(0), totalSecond(0.0), music_index(0){}
        Music() = default;
        ~Music(){};

        void InitMusic();
        void playMusic();
        void playMusic(std::thread& thread);
        void pauseMusic();
        void resumeMusic();
        void stopMusic();
        void setVolume(int volume);
        void Next();
        void Previous();
        void QuitMusic();
        void seek(double val);
};
};
#endif // MUSIC_HPP
