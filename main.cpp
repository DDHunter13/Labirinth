#include "Player.h"

int main(void) {

	srand(time(0));

	int width;
	int height;
	int Vbonus;

	std::cout << "Enter the height of the Labyrinth : ";
	std::cin >> height;
	std::cout << std::endl;
	height += 1;

	std::cout << "Enter the width of the Labyrinth : ";
	std::cin >> width;
	std::cout << std::endl;
	width += 2;

	std::cout << "Enter the value of the bonus : ";
	std::cin >> Vbonus;
	std::cout << std::endl;

	int finishI = 1 + rand () % (height - 1);
	int finishJ = 1 + rand () % (width - 2);

	int startI = 1 + rand() % (height - 1);
	while (startI == finishI) { startI = 1 + rand() % (height - 1); }
	int startJ = 1 + rand() % (width - 2);
	while (startJ == finishJ) { startJ = 1 + rand() % (width - 2); }

	Lab Map(width, height, finishI, finishJ);
	Map.CreateLab();

	Player PL(Map, startI, startJ);

	Map.bonusCreator(Vbonus);
	
	system("cls");
	std::cout << Map;

	PL.Move(Map, finishI, finishJ, Vbonus);

	system("pause");
	return 0;
}
