#ifndef MAZEWIDGET_H
#define MAZEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "labyrinth.h"

class QPaintEvent;

class MazeWidget : public QWidget {

    Lab *maze;

public:
    MazeWidget(QWidget *parent = 0);
    void CreateMaze(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bonuses);
protected:
    void paintEvent(QPaintEvent*);
signals:

public slots:
};

#endif // MAZEWIDGET_H
