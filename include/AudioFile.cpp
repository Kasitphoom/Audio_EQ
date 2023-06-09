#include "AudioFile.h"
#define FILE_CACHE_PATH "audio_cache"

std::vector<fs::path> AudioFile::filesData;

void AudioFile::FileInit() {
    AudioFile::InitCacheDir();
    fs::path audioPath = fs::path(FILE_CACHE_PATH);
    std::vector<fs::path> audioFiles;
    for(auto& p: fs::directory_iterator(audioPath)) {
        filesData.push_back(p.path());
    }
}

void AudioFile::FileInit(std::string path){
    fs::path audioPath = fs::path(path);
    std::vector<fs::path> audioFiles;
    for(auto& p: fs::directory_iterator(audioPath)) {
        filesData.push_back(p.path());
    }
}

std::vector<char*> AudioFile::getFileNames() const {
    std::vector<char*> fileNames;
    for (const auto& p : filesData) {
        const std::string& filename = p.filename().string();
        char* filenameCStr = new char[filename.size() + 1];
        std::strcpy(filenameCStr, filename.c_str());
        fileNames.push_back(filenameCStr);
    }
    return fileNames;
}

std::vector<char*> AudioFile::getFilesFullPath() const {
    std::vector<char*> filesFullPath;
    for (const auto& p : filesData) {
        const std::string& fullPath = p.string();
        char* fullPathCStr = new char[fullPath.size() + 1];
        std::strcpy(fullPathCStr, fullPath.c_str());
        filesFullPath.push_back(fullPathCStr);
    }
    return filesFullPath;
}

std::string AudioFile::getFilePath() const{
    return "";
}

void AudioFile::InitCacheDir(){
    fs::path audioPath = fs::path(FILE_CACHE_PATH);
    if(!fs::exists(audioPath)){
        fs::create_directory(audioPath);
    }
}

// AudioFileCache
std::string AudioFileCache::getFilePath() const{
    return FILE_CACHE_PATH;
}

// AudioFileCustom
std::string AudioFileCustom::getFilePath() const{
    return filesData[0].parent_path().string();
}