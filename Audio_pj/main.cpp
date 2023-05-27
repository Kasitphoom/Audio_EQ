#define SDL_MAIN_HANDLED
#include "mainwindow.h"

#include <QApplication>
#include <thread>

int main(int argc, char *argv[])
{
    std::thread thread;

    QApplication a(argc, argv);
    MainWindow w(nullptr, thread);
    w.setWindowTitle("Vibin studio");
    w.show();
    return a.exec();
}
