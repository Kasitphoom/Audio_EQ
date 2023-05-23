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
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(myclicked())); // push play button to change the [Music Name]
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myclicked(){
    ui->label_4->setText(test);
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
