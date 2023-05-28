#define FILE_CACHE_PATH "audio_file"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include "eq.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

static bool setting_open = false;
static bool playlist_click = false;
static bool playsong = false;
static QString clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #FFFFFF;}QPushButton:hover {color: #FFFFFF}";
static QString not_clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #5F84A1;}QPushButton:hover {color: rgb(158, 170, 189)}";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    AF::AudioFile* af;
    af = new AF::AudioFileCache();

    std::vector<char*> songname = af->getFilesFullPath();

    media = new QMediaPlayer();
    auxOut = new QAudioOutput();


    media->setAudioOutput(auxOut);
    connect(media, SIGNAL(positionChange(qint64)), this, SLOT(positionChage(qint64)));

//    media->setSource(QUrl::fromLocalFile("audio_cache/10000hrs.mp3"));

//    auxOut->setVolume(ui->horizontalSlider_2->value());

    ui->setupUi(this);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked(music))); // push play button to change the [Music Name]
    // Connect a button's clicked signal to the populateListWidget() function
//    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::populateListWidget);

    ui->pushButton_14->setStyleSheet(clicked);
    ui->pushButton_28->setStyleSheet(clicked);

    std::cout << songname.size() << std::endl;
    //receive vector of song_names
    for (auto& name: songname){
        QString n = QString::fromUtf8(name);

        ui->listWidget->addItem(n);
    }

    showMain();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myclicked(){
    if(!playsong){
        media->play();
        playsong = true;
        return;
    }
    media->stop();
    playsong = false;
    return;
}

void MainWindow::on_pushButton_clicked()
{

    if (!setting_open){
        showSetting();
        setting_open = true;
    } else {
        showMain();
        setting_open = false;
    }

}

void MainWindow::showMain() {
    //hide setting
    ui->frame_8->hide();
    ui->label_13->hide();
    //show main
    ui->frame_9->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->frame->show();
    //hide playlist
    ui->frame_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->listWidget->hide();
}

void MainWindow::showSetting() {
    //show setting
    ui->frame_8->show();
    ui->label_13->show();
    //hide main
    ui->frame_9->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->frame->hide();
    //hide playlist
    ui->frame_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->listWidget->hide();
}
void MainWindow::on_pushButton_8_clicked()
{
    if (!playlist_click) {
        ui->frame_4->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->listWidget->show();

        ui->label->hide();
        ui->label_2->hide();
        ui->frame->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        playlist_click = true;
    } else {
        ui->frame_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->listWidget->hide();

        ui->label->show();
        ui->label_2->show();
        ui->frame->show();
        ui->label_3->show();
        ui->label_4->show();
        playlist_click = false;
        
    }
}
void MainWindow::on_pushButton_14_clicked()
{
    if (!en){
        ui->pushButton_14->setStyleSheet(clicked);
        ui->pushButton_27->setStyleSheet(not_clicked);
        en = true;
        th = false;
        ui->label_13->setText("SETTINGS");
        ui->label_10->setText("Language");
        ui->label_11->setText("THEME");
        ui->pushButton_28->setText("LIGHTBLUE");
        ui->pushButton_29->setText("DARK");
        ui->label_2->setText("DISCOVER \nYOUR FEEL'N");
        ui->label_3->setText("is playing right now");
    }
}

void MainWindow::on_pushButton_27_clicked() {
    if (!th){
        ui->pushButton_14->setStyleSheet(not_clicked);
        ui->pushButton_27->setStyleSheet(clicked);
        en = false;
        th = true;
        ui->label_13->setText("การตั้งค่า");
        ui->label_10->setText("ภาษา");
        ui->label_11->setText("ธีม");
        ui->pushButton_28->setText("ฟ้าอ่อน");
        ui->pushButton_29->setText("ดำ");
        ui->label_2->setText("ค้นพบ\nความรู้สึกของคุณ");
        ui->label_3->setText("กำลังเล่นอยู่ตอนนี้");
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    auxOut->setVolume(value);
}

