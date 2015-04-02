#pragma once

#include <conio.h>

#include "Player.h"

//конструктор
Player::Player(Lab &map, const int &xx, const int &yy){
	x = xx;
	y = yy;
	map.Arr[x][y].pack = 'x';
}

//Ходы - пока не достгнут финиш и не собраны все бонусы
void Player::Move(Lab &map, const int &ei, const int &ej, const int &b) {
	int bonusValue = 0;
	int flag = 0;
	while ((x != ei) || (y != ej) || (bonusValue != b)) {
		int N = _getch();
		if (N == 27) {
			break;
		}
		if (N == 224) {
			N = _getch();
			switch (N) {
			case UP_ARROW:
				if (map.Arr[x - 1][y].down_wall == 0) {
					if (map.Arr[x - 1][y].pack == '*') { bonusValue++; }
					if (flag == 1) {
						map.Arr[x][y].pack = '#';
						flag = 0;
					}
					else { map.Arr[x][y].pack = ' '; }
					if (map.Arr[x - 1][y].pack == '#') { flag = 1; }
					map.Arr[x - 1][y].pack = 'x';
					x -= 1;
					system("cls");
					std::cout << map;
				}
				break;
			case DOWN_ARROW:
				if (map.Arr[x][y].down_wall == 0) {
					if (map.Arr[x + 1][y].pack == '*') { bonusValue++; }
					if (flag == 1) {
						map.Arr[x][y].pack = '#';
						flag = 0;
					}
					else { map.Arr[x][y].pack = ' '; }
					if (map.Arr[x + 1][y].pack == '#') { flag = 1; }
					map.Arr[x + 1][y].pack = 'x';
					x += 1;
					system("cls");
					std::cout << map;
				}
				break;
			case LEFT_ARROW:
				if (map.Arr[x][y - 1].right_wall == 0) {
					if (map.Arr[x][y - 1].pack == '*') { bonusValue++; }
					if (flag == 1) {
						map.Arr[x][y].pack = '#';
						flag = 0;
					}
					else { map.Arr[x][y].pack = ' '; }
					if (map.Arr[x][y - 1].pack == '#') { flag = 1; }
					map.Arr[x][y - 1].pack = 'x';
					y -= 1;
					system("cls");
					std::cout << map;
				}
				break;
			case RIGHT_ARROW:
				if (map.Arr[x][y].right_wall == 0) {
					if (map.Arr[x][y + 1].pack == '*') { bonusValue++; }
					if (flag == 1) {
						map.Arr[x][y].pack = '#';
						flag = 0;
					}
					else { map.Arr[x][y].pack = ' '; }
					if (map.Arr[x][y + 1].pack == '#') { flag = 1; }
					map.Arr[x][y + 1].pack = 'x';
					y += 1;
					system("cls");
					std::cout << map;
				}
				break;
			}
		}
	}
}
