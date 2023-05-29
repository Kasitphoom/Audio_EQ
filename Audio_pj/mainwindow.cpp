#define FILE_CACHE_PATH "audio_file"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QFileDialog>
#include <QAudioDevice>
#include <QMessageBox>
#include <iostream>

static bool setting_open = false;
static bool playlist_click = false;
static bool playclicked = false;
static bool fileMode = true;
static QString clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #FFFFFF;}QPushButton:hover {color: #FFFFFF}";
static QString not_clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #5F84A1;}QPushButton:hover {color: rgb(158, 170, 189)}";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    af = new AF::AudioFileCache();

    media = new QMediaPlayer();

    auxOut = new QAudioOutput();

    scrollTimer = new QTimer(this);

    const auto devices = QMediaDevices::audioOutputs();
    for (const QAudioDevice &device : devices){
        OutputDevices.push_back(device);
    }

    QAudioFormat format;
    // Set up the format, eg.
    format.setSampleRate(48000);
    format.setChannelCount(2);
    format.setSampleFormat(QAudioFormat::UInt8);

    QAudioDevice info(QMediaDevices::defaultAudioOutput());
    if (!info.isFormatSupported(format)) {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return;
    }


    media->setAudioOutput(auxOut);

    connect(media, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    auxOut->setVolume(80);

    setSource();


    connect(media, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(media, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    ui->setupUi(this);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked(music))); // push play button to change the [Music Name]

    connect(scrollTimer, SIGNAL(timeout()), this, SLOT(scrollText()));

    ui->pushButton_14->setStyleSheet(clicked);
    ui->pushButton_28->setStyleSheet(clicked);
    //receive vector of song_names

    update_playlist();

    showMain();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSource(){
    if (af->getFilesFullPath().size() == 0) return;

    QString filePaths = QString::fromUtf8(af->getFilesFullPath()[af->CurrentIndex()]);
    media->setSource(QUrl::fromLocalFile(filePaths));
}

void MainWindow::durationChanged(qint64 duration)
{
    mediaPos = duration / 1000;
    ui->horizontalSlider->setMaximum(mediaPos);
}

void MainWindow::positionChanged(qint64 pos)
{
    if(!ui->horizontalSlider->isSliderDown()){
        ui->horizontalSlider->setValue(pos / 1000);
    }
    updateduration(pos / 1000);
}

void MainWindow::updateduration(qint64 duration)
{
    QString timestr;
    if (duration || mediaPos){
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime TotalTime((mediaPos / 3600) % 60, (mediaPos / 60) % 60, (mediaPos % 60), (mediaPos * 1000) % 1000);
        QString format = "mm:ss";
        if(mediaPos > 3600) format = "hh:mm:ss";
        ui->current_time->setText(CurrentTime.toString(format));
        ui->total_time->setText(TotalTime.toString(format));
    }
}

double MainWindow::map(double value, double min1, double max1, double min2, double max2) {
    return min2 + (max2 - min2) * ((value - min1) / (max1 - min1));
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
    update_outputdevice();
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
        ui->label_5->setText("is playing right now");
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
        ui->label_5->setText("กำลังเล่นอยู่ตอนนี้");
    }
}

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


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    auxOut->setVolume(map(value, 0, 100, 0, 1));
}


void MainWindow::on_pushButton_6_clicked()
{
    if (af->getFilesFullPath().size() == 0){
        QMessageBox::critical(this, tr("VIBIN STUDIO APPLICATION"), tr("NO FILE EXIST\n\nin folder\n\nPlease import file to play"), QMessageBox::Ok);
        return;
    }
    update_filename();
    if(!playclicked){
        media->play();
        playclicked = true;
        QString button_pause_image = "";
        if (lightblue){
            button_pause_image = "button-pause.png";
        }else if(tokyo){
            button_pause_image = "button-pause2.png";
        }
        ui->pushButton_6->setStyleSheet(
                    "QPushButton {\
                        background-image: url(:/" + button_pause_image + ");\
                        background-repeat: no-repeat;\
                        background-position: center;\
                        border: none;\
                    }");
        return;
    }
    media->pause();
    playclicked = false;
    QString button_play_image = "";
    if (lightblue){
        button_play_image = "button-play-solid.png";
    }else if(tokyo){
        button_play_image = "button-play-solid2.png";
    }
    ui->pushButton_6->setStyleSheet(
                "QPushButton {\
                    background-image: url(:/" + button_play_image + ");\
                    background-repeat: no-repeat;\
                    background-position: center;\
                    border: none;\
                }");
    return;
}

void MainWindow::update_filename(){
    QFileInfo File(QString::fromUtf8(af->getFileNames()[af->CurrentIndex()]));
    this->name = File.baseName() + " ";
    ui->label_4->setText(this->name);
    ui->label_6->setText(this->name);
    scrollText();
}

void MainWindow::on_pushButton_7_clicked()
{
    if (af->getFilesFullPath().size() == 0){
        QMessageBox::critical(this, tr("VIBIN STUDIO APPLICATION"), tr("NO FILE EXIST\n\nin folder\n\nPlease import file to play"), QMessageBox::Ok);
        return;
    }
    std::cout << "Skip" <<std::endl;
    af->Next();
    update_filename();
    setSource();
    std::cout << af->getFileNames()[af->CurrentIndex()] << std::endl;
    media->play();
    playclicked = true;
    QString next_button_pause_image = "";
    if (lightblue){
        next_button_pause_image = "button-pause.png";
    }else if(tokyo){
        next_button_pause_image = "button-pause2.png";
    }
    ui->pushButton_6->setStyleSheet(
                "QPushButton {\
                    background-image: url(:/" + next_button_pause_image + ");\
                    background-repeat: no-repeat;\
                    background-position: center;\
                    border: none;\
                }");
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(ui->horizontalSlider->value() == mediaPos){
        ui->horizontalSlider->setValue(0);
        ui->horizontalSlider->setSliderPosition(0);
        ui->pushButton_7->click();
    }
}


void MainWindow::on_horizontalSlider_sliderPressed()
{

}


void MainWindow::on_horizontalSlider_sliderReleased()
{
    media->setPosition(ui->horizontalSlider->value() * 1000);
}


void MainWindow::on_pushButton_5_clicked()
{
    if (af->getFilesFullPath().size() == 0){
        QMessageBox::critical(this, tr("VIBIN STUDIO APPLICATION"), tr("NO FILE EXIST\n\nin folder auid_cache\n\nPlease import file to play"), QMessageBox::Ok);
        return;
    }
    af->Previous();
    update_filename();
    setSource();
    media->play();
    playclicked = true;
    QString back_button_pause_image = "";
    if (lightblue){
        back_button_pause_image = "button-pause.png";
    }else if(tokyo){
        back_button_pause_image = "button-pause2.png";
    }
    ui->pushButton_6->setStyleSheet(
                "QPushButton {\
                    background-image: url(:/" + back_button_pause_image + ");\
                    background-repeat: no-repeat;\
                    background-position: center;\
                    border: none;\
                }");
}




void MainWindow::on_Shuffle_btn_clicked()
{
    af->Shuffle();
    update_playlist();
}

void MainWindow::update_playlist()
{
    std::cout << "updating playlist...." << std::endl;
    ui->listWidget->clear();
    for (auto& p: af->getFileNames()){
        QFileInfo Files(QString::fromUtf8(p));
        ui->listWidget->addItem(Files.baseName());
    }
    std::cout << "playlist updated!!" << std::endl;
}


void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    int index = ui->listWidget->indexFromItem(item).row();
    af->SetSongAtIndex(index);
    update_filename();
    setSource();
    media->play();
    playclicked = true;
    QString plbutton_pause_image = "";
    if (lightblue){
        plbutton_pause_image = "button-pause.png";
    }else if(tokyo){
        plbutton_pause_image = "button-pause2.png";
    }
    ui->pushButton_6->setStyleSheet(
                "QPushButton {\
                    background-image: url(:/"+ plbutton_pause_image +");\
                    background-repeat: no-repeat;\
                    background-position: center;\
                    border: none;\
                }");
}


void MainWindow::on_ImportFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Song"), "", tr("Audio Files (*.wav *.mp3 *.flac)"));
    QFile file(fileName);
    QFileInfo fileinfo(fileName);


    if (file.exists()) {
        af = new AF::AudioFileCache();

        if(!fileMode){
            int info = QMessageBox::information(this, tr("MODE CHANGE"), tr("You will be prompt to use file mode after this. \n\n Are you sure to change?"), QMessageBox::Ok | QMessageBox::Cancel);
            switch(info){
                case QMessageBox::Cancel:
                    std::cout << "cancel" << std::endl;
                    return;
            }
        }
        QString dest = QString::fromUtf8(af->getFilePath().c_str());\
        QFileInfo destInfo(dest);
        QString destPath(destInfo.path());
        QDir destDir(destPath);

        if(!destDir.exists()){
            std::cout << destDir.path().toStdString() << " does not exist" << std::endl;
            return;
        }
        std::cout << "Destination path: " << dest.toStdString() << std::endl;


        if (file.copy(dest + QDir::separator() + fileinfo.fileName())) {
            std::cout << "Success move file: " << file.fileName().toStdString() << " to " << (dest + QDir::separator() + fileinfo.fileName()).toStdString() << std::endl;
            af->UpdateFiles();
            update_playlist();
            setSource();
            return;
        } else {
            std::cout << "Failed to move file" << file.fileName().toStdString() << " to " << (dest + QDir::separator() + fileinfo.fileName()).toStdString() << std::endl;
            return;
        }
    } else {
        std::cout << "File does not exist" << std::endl;
        return;
    }
}




void MainWindow::on_ImportFolder_clicked()
{
    QString filename= QFileDialog::getExistingDirectory(this,"Choose Folder");
    if (filename.isEmpty()) return;
    ui->listWidget->clear();
    af = new AF::AudioFileCustom(filename.toStdString());
    update_playlist();
    fileMode = false;
}

void MainWindow::update_outputdevice()
{
    ui->listWidget_2->clear();
    for(auto& device: OutputDevices){
        ui->listWidget_2->addItem(device.description());
    }
}

void MainWindow::Lightblue() {
    this->setStyleSheet("background-color: rgb(144, 175, 196);");
    ui->frame_5->setStyleSheet("background-color:   #1A4568   ;border-radius: 25px;");
    ui->frame_6->setStyleSheet("background-color:   #1A4568   ;border-radius: 25px;");
    ui->label_13->setStyleSheet("font-style: normal;\
                                font-weight: 2000;\
                                font-size: 27px;\
                                line-height: 41px;\
                                letter-spacing: -1px;\
                                color: #1A4568;");
    ui->centralwidget->setStyleSheet("background-color: rgb(144, 175, 196);");
    ui->frame->setStyleSheet("background-image: url(:/Dis_pic.png);");
    ui->ImportFolder->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-Vector.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->ImportFile->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-file-import.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->Shuffle_btn->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-shuffle.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->pushButton_8->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-list.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->label->setStyleSheet("QLabel {\
                            background-color: rgb(95, 132, 161);\
                            border-radius: 151px;\
                            }");
    ui->label_2->setStyleSheet("letter-spacing: -2px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                background-color: transparent;\
                                color: #1A4568	\
                                ");
    ui->pushButton_5->setStyleSheet("QPushButton {\
        background-image: url(:/button-backward-solid.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    QString button_after_changed = "";
    if(media->playbackState()==0 || media->playbackState()==2){
        button_after_changed = "button-play-solid.png";
    }else{
        button_after_changed = "button-pause.png";
    }
    ui->pushButton_6->setStyleSheet("QPushButton {\
        background-image: url(:/" + button_after_changed + ");\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->pushButton_7->setStyleSheet("QPushButton {\
        background-image: url(:/button-forward-solid.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->frame_2->setStyleSheet("QFrame {\
        background-image: url(:/voulume-off-solid.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->frame_3->setStyleSheet("QFrame {\
        background-image: url(:/volume-high-solid.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->pushButton->setStyleSheet("QPushButton {\
        background-image: url(:/gear-solid.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->label_4->setStyleSheet("letter-spacing: -1px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                font-size: 25px;\
                                line-height: 38px;\
                                text-align: center;\
                                color: #1A4568;\
                                qproperty-alignment: 'AlignCenter';");
    ui->label_3->setStyleSheet("QLabel{\
                                qproperty-alignment: 'AlignCenter';\
                                background-color: transparent;\
                                color: #B6D0E1\
                                }");
    ui->frame_4->setStyleSheet("image: url(:/Dis_pic.png);\
                                background-color: transparent;");
    ui->label_6->setStyleSheet("letter-spacing: -1px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                font-size: 25px;\
                                line-height: 38px;\
                                text-align: center;\
                                color: #1A4568;\
                                background-color: transparent;\
                                qproperty-alignment: 'AlignCenter';");
    ui->label_5->setStyleSheet("QLabel{\
                                qproperty-alignment: 'AlignCenter';\
                                background-color: transparent;\
                                color: #B6D0E1\
                                }");
    ui->listWidget->setStyleSheet("background-color: rgb(182, 208, 225); color: rgb(26, 69, 104);");
}

void MainWindow::Tokyo() {
    this->setStyleSheet("background-color: #100043;");
    ui->frame_5->setStyleSheet("background-color:   #7B007C   ;border-radius: 25px;");
    ui->frame_6->setStyleSheet("background-color:   #7B007C   ;border-radius: 25px;");
    ui->label_13->setStyleSheet("font-style: normal;\
                                font-weight: 2000;\
                                font-size: 27px;\
                                line-height: 41px;\
                                letter-spacing: -1px;\
                                color: #7B007C;");
    ui->centralwidget->setStyleSheet("background-color: #100043;");
    ui->frame->setStyleSheet("background-image: url(:/Dis_pic2.png);");
    ui->ImportFolder->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-Vector2.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->ImportFile->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-file-import2.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->Shuffle_btn->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-icon-shuffle2.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->pushButton_8->setStyleSheet("QPushButton {\
                                    background-image: url(:/button-list2.png);\
                                    background-repeat: no-repeat;\
                                    background-position: center;\
                                    border: none;\
                                    }");
    ui->label->setStyleSheet("QLabel {\
                            background-color: #282DB1;\
                            border-radius: 151px;\
                            }");
    ui->label_2->setStyleSheet("letter-spacing: -2px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                background-color: transparent;\
                                color: #008D87	\
                                ");
    ui->pushButton_5->setStyleSheet("QPushButton {\
        background-image: url(:/button-backward-solid2.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    QString button_after_changed = "";
    if(media->playbackState()==0 || media->playbackState()==2){
        button_after_changed = "button-play-solid2.png";
    }else{
        button_after_changed = "button-pause2.png";
    }
    ui->pushButton_6->setStyleSheet("QPushButton {\
        background-image: url(:/" + button_after_changed + ");\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->pushButton_7->setStyleSheet("QPushButton {\
        background-image: url(:/button-forward-solid2.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->frame_2->setStyleSheet("QFrame {\
        background-image: url(:/voulume-off-solid2.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->frame_3->setStyleSheet("QFrame {\
        background-image: url(:/volume-high-solid2.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->pushButton->setStyleSheet("QPushButton {\
        background-image: url(:/gear-solid2.png);\
        background-repeat: no-repeat;\
        background-position: center;\
        border: none;\
    }");
    ui->label_4->setStyleSheet("letter-spacing: -1px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                font-size: 25px;\
                                line-height: 38px;\
                                text-align: center;\
                                color: #7B007C;\
                                qproperty-alignment: 'AlignCenter';");
    ui->label_3->setStyleSheet("QLabel{\
                                qproperty-alignment: 'AlignCenter';\
                                background-color: transparent;\
                                color: #008D87\
                                }");
    ui->frame_4->setStyleSheet("image: url(:/Dis_pic2.png);\
                                background-color: transparent;");
    ui->label_6->setStyleSheet("letter-spacing: -1px;\
                                font-style: normal;\
                                font-weight: 2000;\
                                font-size: 25px;\
                                line-height: 38px;\
                                text-align: center;\
                                color: #7B007C;\
                                background-color: transparent;\
                                qproperty-alignment: 'AlignCenter';");
    ui->label_5->setStyleSheet("QLabel{\
                                qproperty-alignment: 'AlignCenter';\
                                background-color: transparent;\
                                color: #008D87\
                                }");

    ui->listWidget->setStyleSheet("background-color: transparent; color: #7B007C;");

}


void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    QModelIndex indexItem = ui->listWidget_2->indexFromItem(item);
    int index = indexItem.row();
    for(auto& selected: ui->listWidget->selectedItems()){
        selected->setSelected(false);
        selected->background().color().fromRgb(0, 0, 0, 0);
        selected->foreground().color().fromRgb(26, 69, 104);
    }
    ui->listWidget_2->itemFromIndex(indexItem)->setSelected(true);
    auxOut->setDevice(OutputDevices[index]);
}


void MainWindow::on_listWidget_2_itemSelectionChanged()
{
    for(auto& selected: ui->listWidget->selectedItems()){
        selected->background().color().fromRgb(26, 69, 104);
        selected->foreground().color().fromRgb(255, 255, 255);
    }
}

void MainWindow::scrollText()
{
    if (ui->label_4->text().length() <= 20) {
        return;
    } else {
        if (scrollTimer && !scrollTimer->isActive()) {
            scrollTimer->start(200);
        }
    }

    // Get the current text of the label
    QString labelText = ui->label_4->text();
    QString labelText2 = ui->label_6->text();

    // Shift the text by one character to the left
    QString newText = labelText.mid(1) + labelText.at(0);
    QString newText2 = labelText2.mid(1) + labelText2.at(0);

    // Set the new text to the label
    ui->label_4->setText(newText);
    ui->label_6->setText(newText2);
}


