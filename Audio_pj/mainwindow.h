#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include "eq.h"
#include "Music.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString test;

public:
    MainWindow(QWidget *parent = nullptr, std::thread thread = thread);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void myclicked(MUS::Music& m, std::thread thread);

private:
    Ui::MainWindow *ui;
    EQ *eq;
    std::thread thread;
};
#endif // MAINWINDOW_H
