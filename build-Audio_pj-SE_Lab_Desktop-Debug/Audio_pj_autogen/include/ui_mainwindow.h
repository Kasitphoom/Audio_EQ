/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 800);
        MainWindow->setMinimumSize(QSize(400, 800));
        MainWindow->setMaximumSize(QSize(400, 800));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(144, 175, 196);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-95, -174, 303, 303));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(303, 303));
        label->setMaximumSize(QSize(303, 303));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgb(95, 132, 161);\n"
"	border-radius: 151px;\n"
"}"));
        label->setFrameShape(QFrame::NoFrame);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 151, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Condensed")});
        font.setPointSize(27);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        label_2->setFont(font);
        label_2->setTabletTracking(false);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: transparent;\n"
"	color: #1A4568\n"
"}"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(70, 360, 256, 192));
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QGraphicsView::viewport {\n"
"    background-color: transparent;\n"
"    border-radius: 80px;\n"
"}\n"
"\n"
"QGraphicsView::frame {\n"
"    border-radius: 40px;\n"
"    border-width: 2px;\n"
"    border-color: black;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 230, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "DISCOVER \n"
"YOUR FEEL'N", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
