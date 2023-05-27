#define FILE_CACHE_PATH "audio_file"

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include "eq.h"

static bool EQ_open = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked(music))); // push play button to change the [Music Name]
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myclicked(MUS::Music& m){
    ui->label_4->setText(test);
    //m.playMusic(thread);
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
