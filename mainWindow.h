#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    //Отрисовка лабиринта
    MazeWidget *mainW;
    //Главный слой
    QHBoxLayout *mainLay = new QHBoxLayout;
    //Слой для хранения строк ввода параметров лабиринта
    QVBoxLayout *vertLayText = new QVBoxLayout;
    //СЛой для хранения кнопок
    QVBoxLayout *vertLayButtons = new QVBoxLayout;
    //Подписи к строкам ввода
    QLabel *height = new QLabel;
    QLabel *width = new QLabel;
    QLabel *bonus = new QLabel;
    //Кнопки Создания, Выхода и Запуска бота
    QPushButton *Create = new QPushButton;
    QPushButton *Exit = new QPushButton;
    QPushButton *Bot = new QPushButton;
    //СТроки для ввода параметров лабиринта
    QSpinBox *lineH = new QSpinBox;
    QSpinBox *lineW = new QSpinBox;
    QSpinBox *lineB = new QSpinBox;
    //Таймер для работы бота (для возможности прерывания)
    QTimer *timer = new QTimer(this);

public:
    mainWindow(QWidget *parent = 0);
    ~mainWindow();

public slots:
    //Выхов генератора лабиринта
    void createClicked (int H, int W, int VB);
    //Чтение информации из спинбоксов
    void readSpinBox();
    //Вызов бота
    void BotStart1();
    //Изменение максимального кол-ва бонусов в лабиринте
    void MaxBonusesChange();
    //Для единичного хода бота
    void g1();

signals:

};

#endif // MAINWINDOW_H

