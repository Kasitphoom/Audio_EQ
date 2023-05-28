#include "mainwindow.h"

#include <QApplication>
#include <thread>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Prompt-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Prompt-Regular.ttf");
    QFontDatabase db;
      for(int i=0; i<db.families().size(); i++)
      {
        qDebug() << db.families().at(i);
      }
    MainWindow w;
    w.setWindowTitle("Vibin studio");
    w.show();
    return a.exec();
}

//void changeLan(MainWindow& main) {
//    //main.setT
//}
