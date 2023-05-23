#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include "eq.h"

static bool EQ_open = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
