#define FILE_CACHE_PATH "audio_file"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include "eq.h"

static bool setting_open = false;
static bool playlist_click = false;
static bool playclicked = false;
static QString clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #FFFFFF;}QPushButton:hover {color: #FFFFFF}";
static QString not_clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #5F84A1;}QPushButton:hover {color: rgb(158, 170, 189)}";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    AF::AudioFile* af;
    af = new AF::AudioFileCache();

    media = new QMediaPlayer();
    auxOut = new QAudioOutput();
    media->setAudioOutput(auxOut);
    connect(media, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    QString filename = QString::fromUtf8(af->getFilesFullPath()[af->CurrentIndex()]);
    media->setSource(QUrl::fromLocalFile(filename));
    auxOut->setVolume(100);
//    media->play();

    ui->setupUi(this);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked(music))); // push play button to change the [Music Name]
    // Connect a button's clicked signal to the populateListWidget() function
//    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::populateListWidget);

    ui->pushButton_14->setStyleSheet(clicked);
    ui->pushButton_28->setStyleSheet(clicked);
    //receive vector of song_names

    for (auto& p: af->getFileNames()){
        ui->listWidget->addItem(QString::fromUtf8(p));
    }
    
    showMain();
}

MainWindow::~MainWindow()
{
    delete ui;
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

//void MainWindow::populateListWidget()
//{
//    QString folderPath = "../album/playlist1"; // Replace with the actual folder path

//    QDir directory(folderPath);
//    QStringList fileList = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);

//    ui->listWidget->clear();

//    foreach (QString fileName, fileList)
//    {
//        ui->listWidget->addItem(fileName);
//    }
//}
void MainWindow::on_pushButton_28_clicked()
{
    if (!lightblue) {
        ui->pushButton_29->setStyleSheet(not_clicked);
        ui->pushButton_28->setStyleSheet(clicked);
        Lightblue();
        lightblue = true;
        tokyo = false;
    }
}
void MainWindow::on_pushButton_29_clicked()
{
    if (!tokyo) {
        ui->pushButton_28->setStyleSheet(not_clicked);
        ui->pushButton_29->setStyleSheet(clicked);
        Tokyo();
        lightblue = false;
        tokyo = true;
    }
}

void MainWindow::Lightblue() {
    ui->frame_5->setStyleSheet("background-color:   #1A4568   ;border-radius: 25px;;");
    ui->frame_6->setStyleSheet("background-color:   #1A4568   ;border-radius: 25px;;");
}

void MainWindow::Tokyo() {
    ui->frame_5->setStyleSheet("background-color:   #7B007C   ;border-radius: 25px;;");
    ui->frame_6->setStyleSheet("background-color:   #7B007C   ;border-radius: 25px;;");
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    auxOut->setVolume(value);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->label_4->setText(test);
    if(!playclicked){
        media->play();
        playclicked = true;
        return;
    }
    media->stop();
    playclicked = false;
    return;
}

