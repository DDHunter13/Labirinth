#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

#include "labyrinth.h"

//Конструктор копирования
Lab::Lab(const Lab& Map1){
    H = Map1.H;
    W = Map1.W;
    Arr = new item*[H];
    for (int i = 0; i < H; i++) {
        Arr[i] = new item[W];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            Arr[i][j].pack = Map1.Arr[i][j].pack;
            Arr[i][j].down_wall = Map1.Arr[i][j].down_wall;
            Arr[i][j].right_wall = Map1.Arr[i][j].right_wall;
            Arr[i][j].point = Map1.Arr[i][j].point;
            Arr[i][j].ff = Map1.Arr[i][j].ff;
        }
    }
}

// Оператор присваивания
Lab& Lab::operator = (const Lab& lb){

    if (this == &lb) { return *this; }

    H = lb.H;
    W = lb.W;
    Arr = new item*[H];
    for (int i = 0; i < H; i++) {
        Arr[i] = new item[W];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            Arr[i][j].pack = lb.Arr[i][j].pack;
            Arr[i][j].down_wall = lb.Arr[i][j].down_wall;
            Arr[i][j].right_wall = lb.Arr[i][j].right_wall;
            Arr[i][j].point = lb.Arr[i][j].point;
            Arr[i][j].ff = lb.Arr[i][j].ff;
        }
    }
    return *this;
}

//Конструктор
Lab::Lab(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst) {
    W = width;
    H = height;
    Arr = new item*[H];
    for (int i = 0; i < H; i++) {
        Arr[i] = new item[W];
    }
    Arr[ixit][jxit].pack = '#';
    Arr[ist][jst].pack = 'x';
    exI = ixit;
    exJ = jxit;
    stI = ist;
    stJ = jst;

}

//Деструктор
Lab::~Lab() {
    for (int i = 0; i < H; i++) {
        delete[] Arr[i];
    }
    delete[] Arr;
}

//вывод лабиринта
 std::ostream& operator << (std::ostream& os, const Lab& out) {
    for (int i = 0; i < out.H - 1; ++i) {
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
void Lab::CreateLab() {

    //множество
    int multiplicity = 1;
    // флаг (исп для проверки стен снизу)
    int flag = 0;

    //начальное присвоение множеств первой строке лабиринта
    for (int j = 1; j < W - 1; ++j) {
        Arr[1][j].point = multiplicity++;
    }

    //цикл построения лабиринта до предпоследней строки включительно
    for (int i = 1; i < H - 2; ++i) {

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
        Arr[H - 2][i].down_wall = 1;
    }
    Nul();
}

// Обнуление множеств и флагов
void Lab::Nul(){
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W - 1; ++j){
            Arr[i][j].point = 0;
            Arr[i][j].ff = 0;
        }
    }
}


//Расстановка бонусов
void Lab::bonusCreator(const int b) {
    for (int i = 0; i < b; ++i) {
        int xx = 1 + rand() % (H - 2);
        int yy = 1 + rand() % (W - 2);
        while ((Arr[xx][yy].pack == '*') || (Arr[xx][yy].pack == '#') || (Arr[xx][yy].pack == 'x')){
            int xx = 1 + rand() % (H - 1);
            int yy = 1 + rand() % (W - 2);
        }
        Arr[xx][yy].pack = '*';
    }
}
