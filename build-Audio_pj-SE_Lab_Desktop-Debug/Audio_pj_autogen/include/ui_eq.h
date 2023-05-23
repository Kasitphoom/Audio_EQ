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
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_6;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_8;
    QSlider *verticalSlider_9;
    QSlider *verticalSlider_10;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label;
    QFrame *frame_2;
    QSlider *verticalSlider_2;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
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
        frame->setGeometry(QRect(230, 100, 591, 300));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
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
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 260, 51, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(110, 260, 51, 31));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 260, 51, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(250, 260, 51, 31));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_12 = new QLabel(frame);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(330, 260, 51, 31));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(400, 260, 51, 31));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(470, 260, 51, 31));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_15 = new QLabel(frame);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(540, 260, 51, 31));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_16 = new QLabel(frame);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(-10, 240, 51, 31));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_17 = new QLabel(frame);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(0, 0, 51, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label_18 = new QLabel(frame);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(0, 120, 51, 31));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 381, 51));
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
        frame_2->setGeometry(QRect(30, 120, 151, 261));
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
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 10, 81, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("font-weight: 2000;\n"
"font-size: 20px;\n"
"line-height: 24px;\n"
"text-align: center;\n"
"color: #FFFFFF;"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 60, 93, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 90, 93, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 120, 93, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(40, 150, 93, 29));
        pushButton_5->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
""));
        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 180, 93, 29));
        pushButton_6->setStyleSheet(QString::fromUtf8("font-style: normal;\n"
"font-weight: 2000;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"text-align: left;\n"
"color: #5F84A1;\n"
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
        label_8->setText(QCoreApplication::translate("EQ", "    100", nullptr));
        label_9->setText(QCoreApplication::translate("EQ", "    200", nullptr));
        label_10->setText(QCoreApplication::translate("EQ", "    400", nullptr));
        label_11->setText(QCoreApplication::translate("EQ", "    800", nullptr));
        label_12->setText(QCoreApplication::translate("EQ", "   1K", nullptr));
        label_13->setText(QCoreApplication::translate("EQ", "   2K", nullptr));
        label_14->setText(QCoreApplication::translate("EQ", "   8K", nullptr));
        label_15->setText(QCoreApplication::translate("EQ", "  16K", nullptr));
        label_16->setText(QCoreApplication::translate("EQ", "   -16dB", nullptr));
        label_17->setText(QCoreApplication::translate("EQ", "+16dB", nullptr));
        label_18->setText(QCoreApplication::translate("EQ", "    0dB", nullptr));
        label->setText(QCoreApplication::translate("EQ", "ENHANCE YOUR MOOD", nullptr));
        label_7->setText(QCoreApplication::translate("EQ", "PRESET", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EQ", "NORMAL", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EQ", "POP", nullptr));
        pushButton_4->setText(QCoreApplication::translate("EQ", "CLASSIC", nullptr));
        pushButton_5->setText(QCoreApplication::translate("EQ", "JAZZ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("EQ", "ROCK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EQ: public Ui_EQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQ_H
