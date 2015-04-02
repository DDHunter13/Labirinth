#pragma once

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

public:

	friend class Player;

	//Конструктор
	Lab(const int, const int , const int &, const int &);

	//Деструктор
	~Lab();

	//генерация лабиринта
	void CreateLab();

	//Расстановка бонусов
	void bonusCreator(const int);

	//вывод лабиринта
	friend std::ostream& operator << (std::ostream&, const Lab&);
};	
