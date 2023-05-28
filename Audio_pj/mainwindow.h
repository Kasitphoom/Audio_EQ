#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <QtMultimedia>
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
    void myclicked();

    void on_pushButton_8_clicked();
    void showMain();
    void showSetting();
    void on_pushButton_27_clicked();
    void on_pushButton_14_clicked();
//    void populateListWidget();
    void Tokyo();
    void Lightblue();
    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    EQ *eq;
    QMediaPlayer *media;
    QAudioOutput *auxOut;
};

#endif // MAINWINDOW_H
