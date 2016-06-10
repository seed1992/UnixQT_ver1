#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //讓背景transparent
    w.setWindowOpacity(1);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    //w.setWindowFlags(Qt::WindowStaysOnTopHint);
    //transparent
    w.show();


    return a.exec();
}

