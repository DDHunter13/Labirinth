#include "player.h"

Player::Player(Lab *map, int x, int y) {
    PMap = map;
    xx = x;
    yy = y;
    PMap->Arr[xx][yy].pack = 'x';
}

Player::~Player(){}

void Player::MoveUp(){
    if (PMap->Arr[xx-1][yy].down_wall == 0){
        if (PMap->Arr[xx-1][yy].pack == '*') {
            PMap->bbb -= 1;
        }
        PMap->Arr[xx][yy].pack = ' ';
        xx -= 1;
        PMap->Arr[PMap->exI][PMap->exJ].pack = '#';
        PMap->Arr[xx][yy].pack = 'x';
    }
}

void Player::MoveDown(){
    if (PMap->Arr[xx][yy].down_wall == 0){
        if (PMap->Arr[xx+1][yy].pack == '*') {
            PMap->bbb -= 1;
        }
        PMap->Arr[xx][yy].pack = ' ';
        xx += 1;
        PMap->Arr[PMap->exI][PMap->exJ].pack = '#';
        PMap->Arr[xx][yy].pack = 'x';
    }
}

void Player::MoveRight(){
    if (PMap->Arr[xx][yy].right_wall == 0){
        if (PMap->Arr[xx][yy+1].pack == '*') {
            PMap->bbb -= 1;
        }
        PMap->Arr[xx][yy].pack = ' ';
        yy += 1;
        PMap->Arr[PMap->exI][PMap->exJ].pack = '#';
        PMap->Arr[xx][yy].pack = 'x';
    }
}

void Player::MoveLeft(){
    if (PMap->Arr[xx][yy-1].right_wall == 0){
        if (PMap->Arr[xx][yy-1].pack == '*') {
            PMap->bbb -= 1;
        }
        PMap->Arr[xx][yy].pack = ' ';
        yy -= 1;
        PMap->Arr[PMap->exI][PMap->exJ].pack = '#';
        PMap->Arr[xx][yy].pack = 'x';
    }
}
