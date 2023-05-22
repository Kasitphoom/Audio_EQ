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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EQ
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EQ)
    {
        if (EQ->objectName().isEmpty())
            EQ->setObjectName("EQ");
        EQ->resize(600, 509);
        EQ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 4);"));
        centralwidget = new QWidget(EQ);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(170, 60, 231, 301));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 390, 93, 29));
        EQ->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EQ);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 26));
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
        pushButton->setText(QCoreApplication::translate("EQ", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EQ: public Ui_EQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQ_H
