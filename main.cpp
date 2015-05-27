#include <QApplication>
#include <QMainWindow>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    mainWindow w;
    w.show();

    return a.exec();
}
