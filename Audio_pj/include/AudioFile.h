#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

namespace fs = std::filesystem;

//QT_BEGIN_NAMESPACE
//namespace AF {class AudioFile;}
//QT_END_NAMESPACE
namespace AF{
class AudioFile{
    protected:
        static std::vector<fs::path> filesData;
        int index = 0;
    public:
        AudioFile(){};
        virtual ~AudioFile(){};
        static void FileInit();
        static void FileInit(std::string path);
        std::vector<char*> getFileNames() const;
        std::vector<char*> getFilesFullPath() const;
        virtual std::string getFilePath() const;
        static void InitCacheDir();
        static void Shuffle();
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
        virtual std::string getFilePath() const override;
};

class AudioFileCustom: public AudioFile{
    public:
        AudioFileCustom(std::string path){AudioFile::FileInit(path);};
        virtual ~AudioFileCustom(){
            filesData.clear();
        };
        virtual std::string getFilePath() const override;
};
};
#endif
