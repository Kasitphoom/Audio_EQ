#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

namespace fs = std::filesystem;

namespace AF{
class AudioFile{
    protected:
        std::vector<fs::path> filesData;
        int index = 0;
    public:
        AudioFile(){};
        virtual ~AudioFile(){};
        void FileInit();
        void FileInit(std::string path);
        std::vector<char*> getFileNames() const;
        std::vector<char*> getFilesFullPath() const;
        virtual std::string getFilePath() const;
        void InitCacheDir();
        void Shuffle();
        virtual void UpdateFiles();
        void SetSongAtIndex(int index);
        void Next();
        void Previous();
        int CurrentIndex() const;
};

class AudioFileCache: public AudioFile{
    public:
        AudioFileCache(){AudioFile::FileInit();};
        virtual ~AudioFileCache(){
            filesData.clear();
        };
        virtual void UpdateFiles();
        virtual std::string getFilePath() const override;
};

class AudioFileCustom: public AudioFile{
    public:
        AudioFileCustom(std::string path){AudioFile::FileInit(path);};
        virtual ~AudioFileCustom(){
            filesData.clear();
        };
        virtual void UpdateFiles();
        virtual std::string getFilePath() const override;
};
};
#endif
