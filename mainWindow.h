#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRegExp>
#include <QLayout>
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

#include "mazewidget.h"

class mainWindow : public QWidget
{
    Q_OBJECT
private:

    MazeWidget *mainW = new MazeWidget;
    QHBoxLayout *mainLay = new QHBoxLayout;
    QVBoxLayout *vertLayText = new QVBoxLayout;
    QVBoxLayout *vertLayButtons = new QVBoxLayout;
    QLabel *height = new QLabel;
    QLabel *width = new QLabel;
    QLabel *bonus = new QLabel;
    QPushButton *Create = new QPushButton;
    QPushButton *Exit = new QPushButton;
    QSpinBox *lineH = new QSpinBox;
    QSpinBox *lineW = new QSpinBox;
    QSpinBox *lineB = new QSpinBox;

public:
    mainWindow(QWidget *parent = 0);
    ~mainWindow();

public slots:
    void createClicked (int H, int W, int VB);
    void readSpinBox();

signals:

};

#endif // MAINWINDOW_H
