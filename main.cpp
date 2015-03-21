#include "Player.h"

int main(void) {
	srand(time(0));
	int width = 12;
	int height = 11;
	int finishI = 1 + rand () % (height - 1);
	int finishJ = 1 + rand () % (width - 1);
	int startI = 1 + rand() % (height - 1);
	int startJ = 1 + rand() % (width - 1);

	Lab Map(width, height, finishI, finishJ);

	Map.CreateLab();
	Player PL(Map, startI, startJ);
	std::cout << Map;



	PL.Move(Map, finishI, finishJ);

	system("pause");
	return 0;
}
