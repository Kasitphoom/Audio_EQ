#include "eq.h"
#include "./ui_eq.h"

EQ::EQ(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EQ)
{
    ui->setupUi(this);
}

EQ::~EQ()
{
    delete ui;
}
