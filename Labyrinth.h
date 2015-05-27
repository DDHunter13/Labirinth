#ifndef LABYRINTH
#define LABYRINTH

#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

//одна клетка лабиринта
struct item {

    //символ в клетке(пусто, игрок, выход, бонус)
    char pack = ' ';
    // стена справа
    int right_wall = 0;
    // стена снизу
    int down_wall = 0;
    // множество (необходимо для генерации лабиринта)
    int point = 0;
    // флаг (нужен для бота)
    int ff = 0;
};

//Лабиринт
class Lab {
private:

    //ширина
    int W;
    //высота
    int H;
    //массив клеток
    item** Arr;
    //Вход
    int stI,stJ;
    //Выход
    int exI, exJ;
    //кол-во бонусов
    int bbb;

public:

    friend class Player;
    friend class Console;
    friend class Ai;
    friend class MazeWidget;

    //Конструктор копирования
    Lab(const Lab&);

    // Оператор присваивания
    Lab& operator = (const Lab& lb);

    //Конструктор
    Lab(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bb);
    Lab(){};

    //Деструктор
    ~Lab();

    //генерация лабиринта
    void CreateLab();

    // Обнуление множеств
    void Nul();

    //Расстановка бонусов
    void bonusCreator();

    //вывод лабиринта
    friend std::ostream& operator << (std::ostream&, const Lab&);

};

#endif // LABYRINTH
