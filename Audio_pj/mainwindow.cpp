#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include "eq.h"

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
    eq = new EQ(this);
    eq->show();

}
