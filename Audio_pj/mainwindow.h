#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eq.h"

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

private:
    void on_pushButton_clicked();
    void myclicked();

private:
    Ui::MainWindow *ui;
    EQ *eq;
};


#endif // MAINWINDOW_H
