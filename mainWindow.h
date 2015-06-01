#ifndef MAZEWIDGET_H
#define MAZEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <conio.h>
#include <windows.h>
#include <QEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QTimer>
#include "labyrinth.h"
#include "ai.h"

class QPaintEvent;

class MazeWidget : public QWidget {


    //Лабиринт
    Lab *maze;
    //Бот
    Ai *bot;
    //Флаг для проверки прохождения
    int flag = 0;

public:

    friend class mainWindow;
    MazeWidget(QWidget *parent = 0);
    //СОздание лабиринта
    void CreateMaze(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bonuses);
    //Перегрузка keyPressEvent для осуществления ходов
    void keyPressEvent(QKeyEvent *pressed);

protected:
    //Отрисовка лабиринта
    void paintEvent(QPaintEvent*);
signals:

public slots:
    //Запуск бота
    void BotStart();
    //Единичные ходы бота
    void BotMove();
};

#endif // MAZEWIDGET_H
