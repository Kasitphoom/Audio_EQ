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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EQ
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QSlider *verticalSlider;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
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
        verticalSlider->setMaximum(100);
        verticalSlider->setOrientation(Qt::Vertical);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(340, 170, 104, 75));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(140, 170, 118, 23));
        progressBar->setValue(24);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 260, 113, 25));
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
    } // retranslateUi

};

namespace Ui {
    class EQ: public Ui_EQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQ_H
