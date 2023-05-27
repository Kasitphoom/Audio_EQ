#define FILE_CACHE_PATH "audio_file"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include "eq.h"
#include "Music.h"
#include "AudioFile.h"
#include "../SDL/x86_64-w64-mingw32/include/SDL2/SDL_mixer.h"
#include "../SDL/x86_64-w64-mingw32/include/SDL2/SDL.h"

static bool EQ_open = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    AF::AudioFile* af;
    af = new AF::AudioFileCache();

    MUS::Music music;
    ui->setupUi(this);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked(music))); // push play button to change the [Music Name]
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myclicked(MUS::Music& m){
    ui->label_4->setText(test);
}

void MainWindow::on_pushButton_clicked()
{
    //EQ eq;
    //eq.show();
    //return eq.QApplication::exec();
    if (!EQ_open){
        eq = new EQ(this);
        eq->show();
        EQ_open = true;
    }
}
void EQ::closeEvent(QCloseEvent *event)
{
    EQ_open = false;
}

std::vector<fs::path> AF::AudioFile::filesData;

void AF::AudioFile::FileInit() {
    AF::AudioFile::InitCacheDir();
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
        filesData.push_back(p.path());
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

// AudioFileCache
std::string AF::AudioFileCache::getFilePath() const{
    return FILE_CACHE_PATH;
}

// AudioFileCustom
std::string AF::AudioFileCustom::getFilePath() const{
    return filesData[0].parent_path().string();
}

// ============================ MUSIC ==========================

void MUS::Music::InitMusic(){
    if (SDL_Init(SDL_INIT_AUDIO) < 0){
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) < 0) {
        std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        return;
    }

    this->current_path = this->all_path[0];
}

void MUS::Music::playMusic(){
    Mix_Chunk* music = Mix_LoadWAV(this->current_path);
    if (music == NULL) {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }

    int channel;

    channel = Mix_PlayChannel(-1, music, 0);
    if(channel == -1){
        std::cout << "Failed to play music: " << Mix_GetError() << std::endl;
    }

    while(Mix_Playing(channel) != 0){
        SDL_Delay(100);
    }

    Mix_FreeChunk(music);
}

void MUS::Music::pauseMusic(){
    Mix_Pause(-1);
}

void MUS::Music::resumeMusic(){
    Mix_Resume(-1);
}

void MUS::Music::stopMusic(){
    Mix_HaltChannel(-1);
}

void MUS::Music::setVolume(int volume){
    Mix_Volume(-1, volume);
}

void MUS::Music::Next(){
    this->music_index++;
    if(this->music_index >= this->all_path.size()){
        this->music_index = 0;
    }
    this->current_path = this->all_path[this->music_index];
}

void MUS::Music::Previous(){
    this->music_index--;
    if(this->music_index < 0){
        this->music_index = this->all_path.size() - 1;
    }
    this->current_path = this->all_path[this->music_index];
}

void MUS::Music::QuitMusic(){
    Mix_CloseAudio();
    SDL_Quit();
    Mix_Quit();
}

void MUS::Music::setPath(std::string path){
    this->all_path.push_back(const_cast<char*>(path.c_str()));
}

void MUS::Music::calculateAudioLength(Mix_Chunk* music, int& minutes, int& seconds, double& totalSeconds){
    int bitPerSample = 8; // Default bit-per-sample value (assuming 8-bit)

    // Get the audio format information
    SDL_AudioFormat format = 0;
    int channels = 0;
    int frequency = 0;
    if (Mix_QuerySpec(&frequency, &format, &channels) == 0) {
        // Failed to get audio format information, use default values
        std::cout << "Failed to get audio format information. Using default values." << std::endl;
    } else {
        bitPerSample = SDL_AUDIO_BITSIZE(format);
    }

    // Calculate the audio length
    Uint32 audioLength = music->alen;
    totalSeconds = static_cast<double>(audioLength) / (channels * bitPerSample / 8 * frequency);

    // Calculate the minutes and seconds
    minutes = static_cast<int>(totalSeconds) / 60;
    seconds = static_cast<int>(totalSeconds) % 60;
}

void MUS::Music::playMusic(std::thread& thread){
    thread = std::thread([this](){
        playMusic();
    });
}
