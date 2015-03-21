#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

//одна клетка лабиринта
class item {             
public:  
	//символ в клетке(пусто, игрок, выход, бонус)                          
	char pack; 
	// стена справа    
	int right_wall;  
	// стена снизу
	int down_wall;   
	// множество (необходимо для генерации лабиринта)
	int point;       

public:
	item() {
		pack = ' ';
		right_wall = 0;
		down_wall = 0;
		point = 0;
	}
	friend class Lab;
};



//Лабиринт
class Lab {             
public:
	//ширина
	int W;
	//высота   
	int H;    
	//массив клеток
	item** Arr; 

public:
	friend class Player;
	Lab(const int width, const int height, const int &ixit, const int &jxit) {
		W = width;
		H = height;
		Arr = new item*[H];
		for (int i = 0; i < H; i++) {
			Arr[i] = new item[W];
		}
		Arr[ixit][jxit].pack = '#';
	}

	~Lab() {
		for (int i = 0; i < H; i++) {
			delete[] Arr[i];
		}
		delete[] Arr;
	}

	//вывод лабиринта
	friend std::ostream& operator << (std::ostream& os, const Lab& out) {
		for (int i = 0; i < out.H; ++i) {
			for (int j = 0; j < out.W - 1; ++j) {
				os << out.Arr[i][j].pack;
				if (out.Arr[i][j].right_wall == 1) { os << '0'; }
				else { os << ' '; }
			}
			os << std::endl;
			for (int j = 0; j < out.W - 1; ++j) {
				if (out.Arr[i][j].down_wall == 1) { os << '0' << '0'; }
				else { os << ' ' << '0'; }
			}
			os << std::endl;
		}
		return os;
	}
	
	
	//генерация лабиринта
	void CreateLab() {    
		//множество                                    
		int multiplicity = 1;  
		// флаг (исп для проверки стен снизу)
		int flag = 0;   

		//начальное присвоение множеств первой строке лабиринта
		for (int j = 1; j < W - 1; ++j) {            
				Arr[1][j].point = multiplicity++;
			}

		//цикл построения лабиринта до предпоследней строки включительно
		for (int i = 1; i < H - 1; ++i) {     

			//цикл расстановки стен справа
			for (int j = 1; j < W - 2; ++j) {   
				if (Arr[i][j].point == Arr[i][j + 1].point) { Arr[i][j].right_wall = 1; }
				else { 
					Arr[i][j].right_wall = rand() % 2;
					if (Arr[i][j].right_wall == 0) { Arr[i][j + 1].point = Arr[i][j].point; }
				}
			}
			//цикл расстановки стен снизу
			for (int j = 1; j < W - 1; ++j) {  
				flag = 0;
				while (Arr[i][j - 1].point == Arr[i][j].point) {
					Arr[i][j - 1].down_wall = rand() % 2;
					if (Arr[i][j - 1].down_wall == 0) { flag = 1; }
					++j;
				}
				if (flag == 1) { Arr[i][j - 1].down_wall = rand() % 2; }
			}
			// цикл сноса множеств в след строку
			for (int j = 1; j < W - 1; ++j) {   
					if (Arr[i][j].down_wall == 1) { Arr[i + 1][j].point = multiplicity++; }
					else { Arr[i + 1][j].point = Arr[i][j].point; }
			}
		}

		//Расстановка правых стен в последней строке
		for (int j = 1; j < W - 1; ++j) {
			if (Arr[H - 1][j].point == Arr[H - 1][j + 1].point) {
				Arr[H - 1][j].right_wall = 1;
			}
		}
	
		//расстановка стен по границам
		for (int i = 1; i < H; ++i) {
			Arr[i][0].right_wall = 1;
			Arr[i][W - 2].right_wall = 1;
		}
		for (int i = 1; i < W; ++i) {
			Arr[0][i].down_wall = 1;
			Arr[H - 1][i].down_wall = 1;
		}
	}
	

};
