#ifndef AI
#define AI


#include "player.h"

#include <queue>
#include <stack>
#include <deque>

// Структура для очереди и стэка
struct que {
    int xx,yy;
};



class Ai {
private:
    // Очередь для хранения точек для обработки ботом
    std::queue<que> Q1;
    // Стэк для составления пути между стартом, бонусом и финишом
    std::stack<que> S;
    // Очередь для хранения пути для полного прохождения лабиринта
    std::queue<que> Q2;
    // Общее кол-во бонусов
    int ABonus;
    // Лабиринт
    Lab AMap;


public:

    friend class Console;

    // Конструктор
    Ai(Lab &, int, int, int);

    // Деструктор
    ~Ai(){};

    // Расстановка множеств в окресность любой клетки лабиринта и добавление их в очередь
    void Surround(que);

    // Поиск всех бонусов
    void BonusSearch();

    // Поиск выхода
    void ExitSearch();

    // Вызов методов для прохождения
    void Exit();

};

#endif // AI
