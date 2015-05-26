#include <QApplication>
#include <QMainWindow>

#include "console.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    mainWindow w;
    w.show();



    /*Console CS;

    int height = CS.GetHeight() + 2;
    int width = CS.GetWidth() + 2;
    int Vbonus = CS.GetBoValue();

    int finishI = 1 + rand () % (height - 2);
    int finishJ = 1 + rand () % (width - 2);

    int startI = 1 + rand() % (height - 2);
    while (startI == finishI) { startI = 1 + rand() % (height - 2); }
    int startJ = 1 + rand() % (width - 2);
    while (startJ == finishJ) { startJ = 1 + rand() % (width - 2); }

    Lab Map(width, height, finishI, finishJ);
    Map.CreateLab();

    Player PL(Map, startI, startJ);

    Map.bonusCreator(Vbonus);

    Console Csl(Map, PL);

    Csl.Out();

    Ai ai(Map, Vbonus, startI, startJ);

    Csl.Mode(ai, finishI, finishJ, Vbonus);

    system("pause");
    return 0;*/

    return a.exec();
}
