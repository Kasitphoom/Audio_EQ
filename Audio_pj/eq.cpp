#include "eq.h"
#include "./ui_eq.h"
#include "mainwindow.h"

static QString clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #FFFFFF;}QPushButton:hover {color: #FFFFFF";
static QString clicked_th = "QPushButton {font-style: normal;font-weight: 2000;font-size: 20px;line-height: 24px;text-align: left;color: #FFFFFF;}QPushButton:hover {color: #FFFFFF";
static QString not_clicked = "QPushButton {font-style: normal;font-weight: 2000;font-size: 16px;line-height: 24px;text-align: left;color: #5F84A1;}QPushButton:hover {color: rgb(158, 170, 189)}";


EQ::EQ(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EQ)
{
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet(clicked);

}

EQ::~EQ()
{
    delete ui;
}


void EQ::on_pushButton_2_clicked()
{

    if (!en){
        ui->pushButton_2->setStyleSheet(clicked);
        ui->pushButton_3->setStyleSheet(not_clicked);
        en = true;
        th = false;
        ui->label->setText("SETTINGS");
        ui->label_7->setText("Language");
        ui->label_8->setText("THEME");
        ui->pushButton_8->setText("LIGHT");
        ui->pushButton_9->setText("BLACK");
        ui->pushButton_10->setText("CUSTOM");
//        ui->label_9->setText("HOTKEYS");
//        ui->pushButton_11->setText("PLAY/PAUSE");
//        ui->pushButton_12->setText("NEXT");
//        ui->pushButton_13->setText("PREVIOUS");
//        ui->pushButton_14->setText("SETTINGS");
//        ui->pushButton_15->setText("IMPORT FILE");
        //ui->pushButton_16->setText("SHUFFLE");
        //ui->pushButton_7->setText("APPLY");

    }
}


void EQ::on_pushButton_3_clicked()
{
    if (!th){
        ui->pushButton_2->setStyleSheet(not_clicked);
        ui->pushButton_3->setStyleSheet(clicked_th);
        en = false;
        th = true;
        ui->label->setText("การตั้งค่า");
        ui->label_7->setText("ภาษา");
        ui->label_8->setText("ธีม");
        ui->pushButton_8->setText("ขาว");
        ui->pushButton_9->setText("ดำ");
        ui->pushButton_10->setText("ปรับเอง");
//        ui->label_9->setText("คีย์ลัด");
//        ui->pushButton_11->setText("เล่น/หยุด");
//        ui->pushButton_12->setText("ถัดไป");
//        ui->pushButton_13->setText("ก่อนหน้า");
//        ui->pushButton_14->setText("การตั้งค่า");
//        ui->pushButton_15->setText("นำเข้าไฟล์");
//        ui->pushButton_16->setText("สลับ");
//        ui->pushButton_7->setText("ตกลง");
    }
}


