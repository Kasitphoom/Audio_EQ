#define SDL_MAIN_HANDLED
#include "mainwindow.h"

#include <QApplication>
#include <thread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Vibin studio");
    w.show();
    return a.exec();
}
