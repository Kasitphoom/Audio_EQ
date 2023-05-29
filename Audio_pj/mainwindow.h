#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <QtMultimedia>
#include <QListWidgetItem>
#include <QTimer>
#include <vector>
#include "AudioFile.h"

static bool en = true;
static bool th = false;
static bool tokyo = false;
static bool lightblue = true;
static int setting = 0;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString test;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // ======Custom made functions====== //
    // Utils
    double map(double value, double min1, double max1, double min2, double max2);
    void showMain();
    void showSetting();
    void update_filename();
    void setSource();
    void update_playlist();
    void update_outputdevice();

    // Themes
    void Tokyo();
    void Lightblue();

    // List
    void durationChanged(qint64 duration);
    void positionChanged(qint64 pos);

    // ======QT made functions====== //

    void on_pushButton_clicked();
    void on_pushButton_8_clicked();    
    void on_pushButton_27_clicked();
    void on_pushButton_14_clicked();    
    void on_pushButton_29_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_Shuffle_btn_clicked();
    void on_ImportFile_clicked();
    void on_ImportFolder_clicked();

    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_sliderPressed();
    void on_horizontalSlider_sliderReleased();


    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_2_itemSelectionChanged();

    void scrollText();

private:
    void updateduration(qint64 duration);

    Ui::MainWindow *ui;
    QMediaPlayer *media;
    QAudioOutput *auxOut;
    AF::AudioFile* af;
    QTimer *scrollTimer;
    QPropertyAnimation *animation;

    qint64 mediaPos;

    QString name;
    std::vector<QAudioDevice> OutputDevices;
};

#endif // MAINWINDOW_H
