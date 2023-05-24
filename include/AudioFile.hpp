#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <cstring>

namespace fs = std::filesystem;

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