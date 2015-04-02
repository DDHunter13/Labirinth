#pragma once

#include <conio.h>

#include "Labyrinth.h"

#define UP_ARROW 72 
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

// Игрок - управление человеком
class Player {
private:

	// Координаты в лабиринте
	int x, y;

public:

	//конструктор
	Player(Lab &, const int &, const int &);

	//деструктор
	~Player(){};

	//Ходы - пока не достгнут финиш и не собраны все бонусы
	void Move(Lab &, const int &, const int &, const int &);
};
