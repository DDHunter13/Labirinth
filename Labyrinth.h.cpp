#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class item {
public:
	char pack = ' ';
	int right_wall = 0;
	int down_wall = 0;
};

class Lab {
public:

	int W;
	int H;
	item** Arr;

public:

	Lab(const int width, const int height) {
		W = width;
		H = height;
		Arr = new item*[H];
		for (int i = 0; i < H; ++i) {
			Arr[i] = new item[W];
		}
	}

	~Lab() {
		for (int i = 0; i < H; ++i) {
			delete[] Arr[i];
		}
		delete[] Arr;
	}

	friend std::ostream& operator << (std::ostream& os, const Lab& out) {
		for (int i = 0; i < out.H; ++i) {
			for (int j = 0; j < out.W; ++j) {
				os << out.Arr[i][j].pack;
				if (out.Arr[i][j].right_wall == 1) { os << '0'; }
				else { os << ' '; }
			}
			os << std::endl;
			for (int j = 0; j < out.W; ++j) {
				if (out.Arr[i][j].down_wall == 1) { os << '0' << '0'; }
				else { os << ' ' << '0'; }
			}
			os << std::endl;
		}
		return os;
	}
	
};
