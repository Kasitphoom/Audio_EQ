#include "AudioFile.h"
#define FILE_CACHE_PATH "audio_cache"
#include <iostream>

void AF::AudioFile::FileInit() {
    AudioFile::InitCacheDir();
    fs::path audioPath = fs::path(FILE_CACHE_PATH);
    std::vector<fs::path> audioFiles;
    for(auto& p: fs::directory_iterator(audioPath)) {
        filesData.push_back(p.path());
    }
}

void AF::AudioFile::FileInit(std::string path){
    fs::path audioPath = fs::path(path);
    std::vector<fs::path> audioFiles;
    for(auto& p: fs::directory_iterator(audioPath)) {
        fs::path filePath = p.path();
        std::string extension = filePath.extension().string();
        if (extension == ".wav" || extension == ".mp3" || extension == ".flac") {
            filesData.push_back(filePath);
        }
    }
}

std::vector<char*> AF::AudioFile::getFileNames() const {
    std::vector<char*> fileNames;
    for (const auto& p : filesData) {
        const std::string& filename = p.filename().string();
        char* filenameCStr = new char[filename.size() + 1];
        std::strcpy(filenameCStr, filename.c_str());
        fileNames.push_back(filenameCStr);
    }
    return fileNames;
}

std::vector<char*> AF::AudioFile::getFilesFullPath() const {
    std::vector<char*> filesFullPath;
    for (const auto& p : filesData) {
        const std::string& fullPath = p.string();
        char* fullPathCStr = new char[fullPath.size() + 1];
        std::strcpy(fullPathCStr, fullPath.c_str());
        filesFullPath.push_back(fullPathCStr);
    }
    return filesFullPath;
}

std::string AF::AudioFile::getFilePath() const{
    return "";
}

void AF::AudioFile::InitCacheDir(){
    fs::path audioPath = fs::path(FILE_CACHE_PATH);
    if(!fs::exists(audioPath)){
        fs::create_directory(audioPath);
    }
}

void AF::AudioFile::Shuffle()
{
    std::random_shuffle(filesData.begin(), filesData.end());
}

void AF::AudioFile::UpdateFiles()
{

}

void AF::AudioFile::SetSongAtIndex(int index)
{
    this->index = index;
}

void AF::AudioFile::Next(){
    if(index + 1 > filesData.size() - 1) {this->index = 0; return;}
    this->index++;
}

void AF::AudioFile::Previous(){
    if(index - 1 < 0) {this->index = filesData.size() - 1; return;}
    this->index--;
}

int AF::AudioFile::CurrentIndex() const{
    return this->index;
}

// AudioFileCache
void AF::AudioFileCache::UpdateFiles()
{
    filesData.clear();
    AudioFile::InitCacheDir();
    fs::path audioPath = fs::path(FILE_CACHE_PATH);
    std::vector<fs::path> audioFiles;
    for(auto& p: fs::directory_iterator(audioPath)) {
        filesData.push_back(p.path());
    }
}

std::string AF::AudioFileCache::getFilePath() const{
    return FILE_CACHE_PATH;
}

// AudioFileCustom
void AF::AudioFileCustom::UpdateFiles()
{

}

std::string AF::AudioFileCustom::getFilePath() const{
    return filesData[0].parent_path().string();
}
