#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <QtMultimedia>
#include <QListWidgetItem>
#include "eq.h"
#include "AudioFile.h"

static bool en = true;
static bool th = false;
static bool tokyo = false;
static bool lightblue = true;
static EQ* eq;
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
    void on_pushButton_clicked();
    double map(double value, double min1, double max1, double min2, double max2);
    void on_pushButton_8_clicked();
    void showMain();
    void showSetting();
    void on_pushButton_27_clicked();
    void on_pushButton_14_clicked();
    void Tokyo();
    void Lightblue();
    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_6_clicked();

    void update_filename();

    void on_pushButton_7_clicked();

    void setSource();

    void durationChanged(qint64 duration);
    void positionChanged(qint64 pos);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_pushButton_5_clicked();

    void on_Shuffle_btn_clicked();

    void update_playlist();

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_ImportFile_clicked();

    void on_ImportFolder_clicked();

private:
    void updateduration(qint64 duration);

    Ui::MainWindow *ui;
    EQ *eq;
    QMediaPlayer *media;
    QAudioOutput *auxOut;
    AF::AudioFile* af;

    qint64 mediaPos;

    QString name;
};

#endif // MAINWINDOW_H
