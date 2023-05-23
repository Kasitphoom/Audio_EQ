/********************************************************************************
** Form generated from reading UI file 'eq.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQ_H
#define UI_EQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EQ
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QSlider *verticalSlider;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_8;
    QSlider *verticalSlider_9;
    QSlider *verticalSlider_10;
    QLabel *label;
    QFrame *frame_2;
    QSlider *verticalSlider_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EQ)
    {
        if (EQ->objectName().isEmpty())
            EQ->setObjectName("EQ");
        EQ->resize(900, 500);
        EQ->setAutoFillBackground(false);
        EQ->setStyleSheet(QString::fromUtf8("background-color: rgb(144,175,196);"));
        centralwidget = new QWidget(EQ);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(210, 80, 650, 300));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalSlider = new QSlider(frame);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(610, 10, 21, 251));
        verticalSlider->setStyleSheet(QString::fromUtf8(""));
        verticalSlider->setMinimum(-16);
        verticalSlider->setMaximum(16);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(frame);
        verticalSlider_3->setObjectName("verticalSlider_3");
        verticalSlider_3->setGeometry(QRect(550, 10, 21, 251));
        verticalSlider_3->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_3->setMinimum(-16);
        verticalSlider_3->setMaximum(16);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_4 = new QSlider(frame);
        verticalSlider_4->setObjectName("verticalSlider_4");
        verticalSlider_4->setGeometry(QRect(480, 10, 21, 251));
        verticalSlider_4->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_4->setMinimum(-16);
        verticalSlider_4->setMaximum(16);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_5 = new QSlider(frame);
        verticalSlider_5->setObjectName("verticalSlider_5");
        verticalSlider_5->setGeometry(QRect(410, 10, 21, 251));
        verticalSlider_5->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_5->setMinimum(-16);
        verticalSlider_5->setMaximum(16);
        verticalSlider_5->setOrientation(Qt::Vertical);
        verticalSlider_6 = new QSlider(frame);
        verticalSlider_6->setObjectName("verticalSlider_6");
        verticalSlider_6->setGeometry(QRect(340, 10, 21, 251));
        verticalSlider_6->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_6->setMinimum(-16);
        verticalSlider_6->setMaximum(16);
        verticalSlider_6->setOrientation(Qt::Vertical);
        verticalSlider_7 = new QSlider(frame);
        verticalSlider_7->setObjectName("verticalSlider_7");
        verticalSlider_7->setGeometry(QRect(270, 10, 21, 251));
        verticalSlider_7->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_7->setMinimum(-16);
        verticalSlider_7->setMaximum(16);
        verticalSlider_7->setOrientation(Qt::Vertical);
        verticalSlider_8 = new QSlider(frame);
        verticalSlider_8->setObjectName("verticalSlider_8");
        verticalSlider_8->setGeometry(QRect(200, 10, 21, 251));
        verticalSlider_8->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_8->setMinimum(-16);
        verticalSlider_8->setMaximum(16);
        verticalSlider_8->setOrientation(Qt::Vertical);
        verticalSlider_9 = new QSlider(frame);
        verticalSlider_9->setObjectName("verticalSlider_9");
        verticalSlider_9->setGeometry(QRect(130, 10, 21, 251));
        verticalSlider_9->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_9->setMinimum(-16);
        verticalSlider_9->setMaximum(16);
        verticalSlider_9->setOrientation(Qt::Vertical);
        verticalSlider_10 = new QSlider(frame);
        verticalSlider_10->setObjectName("verticalSlider_10");
        verticalSlider_10->setGeometry(QRect(60, 10, 21, 251));
        verticalSlider_10->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_10->setMinimum(-16);
        verticalSlider_10->setMaximum(16);
        verticalSlider_10->setOrientation(Qt::Vertical);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 381, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 27px;\n"
"line-height: 41px;\n"
"letter-spacing: -1px;\n"
"\n"
"color: #1A4568;"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 100, 151, 261));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 69, 104);border-radius: 25px;;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalSlider_2 = new QSlider(frame_2);
        verticalSlider_2->setObjectName("verticalSlider_2");
        verticalSlider_2->setGeometry(QRect(610, 10, 21, 251));
        verticalSlider_2->setMinimum(-16);
        verticalSlider_2->setMaximum(16);
        verticalSlider_2->setOrientation(Qt::Vertical);
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 10, 93, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 20px;\n"
"line-height: 24px;\n"
"\n"
"color: #FFFFFF;\n"
""));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 81, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"\n"
"color: #5F84A1;\n"
""));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 90, 81, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"\n"
"color: #5F84A1;\n"
""));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 120, 81, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"\n"
"color: #5F84A1;\n"
""));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 150, 81, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"\n"
"color: #5F84A1;\n"
""));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 180, 81, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"\n"
"color: #5F84A1;\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(230, 380, 93, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 20px;\n"
"line-height: 24px;\n"
"\n"
"color: #FFFFFF;\n"
""));
        EQ->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EQ);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 26));
        EQ->setMenuBar(menubar);
        statusbar = new QStatusBar(EQ);
        statusbar->setObjectName("statusbar");
        EQ->setStatusBar(statusbar);

        retranslateUi(EQ);

        QMetaObject::connectSlotsByName(EQ);
    } // setupUi

    void retranslateUi(QMainWindow *EQ)
    {
        EQ->setWindowTitle(QCoreApplication::translate("EQ", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        verticalSlider->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_3->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_3->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_4->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_4->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_5->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_5->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_6->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_6->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_7->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_7->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_8->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_8->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_9->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_9->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        verticalSlider_10->setToolTip(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        verticalSlider_10->setWhatsThis(QCoreApplication::translate("EQ", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("EQ", "ENHANCE YOUR MOOD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EQ", "PRESET", nullptr));
        label_2->setText(QCoreApplication::translate("EQ", "NORMAL", nullptr));
        label_3->setText(QCoreApplication::translate("EQ", "POP", nullptr));
        label_4->setText(QCoreApplication::translate("EQ", "CLASSIC", nullptr));
        label_5->setText(QCoreApplication::translate("EQ", "JAZZ", nullptr));
        label_6->setText(QCoreApplication::translate("EQ", "ROCK", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EQ", "PRESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EQ: public Ui_EQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQ_H
