#include "Labyrinth.h"
#include <conio.h>

#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define ESC 27

using namespace std;

class Player {
public:
	int x, y;
public:
	Player(Lab &map, const int &xx, const int &yy){
		x = xx;
		y = yy;
		map.Arr[x][y].pack = 'x';
	}

	~Player(){};

	void Move(Lab &map, const int &ei, const int &ej) {
		while ((x != ei) || (y != ej)) {	
			int N = _getch();
			if (N == 27) {
				break;
			}
			if (N == 224) {
				N = _getch();
				switch (N) {
				case UP_ARROW:
					if (map.Arr[x - 1][y].down_wall == 0) {
						map.Arr[x - 1][y].pack = 'x';
						map.Arr[x][y].pack = ' ';
						x -= 1;
						system("cls");
						cout << map;
					}
					break;
				case DOWN_ARROW:
					if (map.Arr[x][y].down_wall == 0) {
						map.Arr[x + 1][y].pack = 'x';
						map.Arr[x][y].pack = ' ';
						x += 1;
						system("cls");
						cout << map;
					}
					break;
				case LEFT_ARROW:
					if (map.Arr[x][y - 1].right_wall == 0) {
						map.Arr[x][y - 1].pack = 'x';
						map.Arr[x][y].pack = ' ';
						y -= 1;
						system("cls");
						cout << map;
					}
					break;
				case RIGHT_ARROW:
					if (map.Arr[x][y].right_wall == 0) {
						map.Arr[x][y + 1].pack = 'x';
						map.Arr[x][y].pack = ' ';
						y += 1;
						system("cls");
						cout << map;
					}
					break;
				}
			}
		}
	}
};
