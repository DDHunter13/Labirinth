#include "Labyrinth.h"

int main(void) {

	int width = 6;
	int height = 6;
	Lab Map(width, height);

	for (int i = 1; i < height; ++i) { 
		Map.Arr[i][0].right_wall = 1;
		Map.Arr[i][width - 1].right_wall = 1;
	}
	for (int i = 1; i < width; ++i) { 
		Map.Arr[0][i].down_wall = 1; 
		Map.Arr[height - 1][i].down_wall = 1;
	}

	Map.Arr[1][1].right_wall = Map.Arr[1][3].right_wall = Map.Arr[2][2].right_wall = Map.Arr[2][3].right_wall = Map.Arr[2][4].right_wall =
		Map.Arr[3][1].right_wall = Map.Arr[3][3].right_wall = Map.Arr[3][4].right_wall = Map.Arr[4][2].right_wall = Map.Arr[4][4].right_wall =
		Map.Arr[5][3].right_wall = 1;

	Map.Arr[1][2].down_wall = Map.Arr[2][1].down_wall = Map.Arr[2][5].down_wall = Map.Arr[4][1].down_wall = Map.Arr[4][3].down_wall = 1;

	std::cout << Map;

	return 0;
}
