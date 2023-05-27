#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <cstring>
#include <QMainWindow>

namespace fs = std::filesystem;

QT_BEGIN_NAMESPACE
namespace AF {class AudioFile;}
QT_END_NAMESPACE

class AudioFile{
    protected:
        static std::vector<fs::path> filesData;
    public:
        AudioFile(){};
        virtual ~AudioFile(){};
        static void FileInit();
        static void FileInit(std::string path);
        std::vector<char*> getFileNames() const;
        std::vector<char*> getFilesFullPath() const;
        virtual std::string getFilePath() const;
        static void InitCacheDir();
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

#endif
