#ifndef PLAYER_H
#define PLAYER_H

#include "labyrinth.h"

class Player {

private:
    //Координаты
    int xx, yy;
    //Лабиринт
    Lab *PMap;

public:

    friend class Console;
    friend class MazeWidget;
    friend class Ai;

    Player(Lab *map, int x, int y);
    ~Player();

    //Ходы
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
};

#endif // PLAYER_H
