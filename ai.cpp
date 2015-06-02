#include "ai.h"

// Контсруктор
Ai::Ai(Lab *L, int B, int sx, int sy, Player *pl){
    AMap = L;
    APla = pl;
    ABonus = B;
    que qq;
    qq.xx = sx;
    qq.yy = sy;
    Q1.push(qq);
    Q2.push(qq);
}

// Расстановка множеств в окресность любой клетки лабиринта и добавление их в очередь
void Ai::Surround(que q1) {
    que qq;
    qq.xx = q1.xx;
    qq.yy = q1.yy;
    if ((AMap->Arr[q1.xx - 1][q1.yy].down_wall == 0) && (AMap->Arr[q1.xx - 1][q1.yy].ff == 0)) {
        AMap->Arr[q1.xx - 1][q1.yy].point = AMap->Arr[q1.xx][q1.yy].point + 1;
        AMap->Arr[q1.xx - 1][q1.yy].ff = 1;
        qq.xx -= 1;
        Q1.push(qq);
        qq.xx += 1;
    }
    if ((AMap->Arr[q1.xx][q1.yy].down_wall == 0) && (AMap->Arr[q1.xx + 1][q1.yy].ff == 0)) {
        AMap->Arr[q1.xx + 1][q1.yy].point = AMap->Arr[q1.xx][q1.yy].point + 1;
        AMap->Arr[q1.xx + 1][q1.yy].ff = 1;
        qq.xx += 1;
        Q1.push(qq);
        qq.xx -= 1;
    }
    if ((AMap->Arr[q1.xx][q1.yy - 1].right_wall == 0) && (AMap->Arr[q1.xx][q1.yy - 1].ff == 0)) {
        AMap->Arr[q1.xx][q1.yy - 1].point = AMap->Arr[q1.xx][q1.yy].point + 1;
        AMap->Arr[q1.xx][q1.yy - 1].ff = 1;
        qq.yy -= 1;
        Q1.push(qq);
        qq.yy += 1;
    }
    if ((AMap->Arr[q1.xx][q1.yy].right_wall == 0) && (AMap->Arr[q1.xx][q1.yy + 1].ff == 0)) {
        AMap->Arr[q1.xx][q1.yy + 1].point = AMap->Arr[q1.xx][q1.yy].point + 1;
        AMap->Arr[q1.xx][q1.yy + 1].ff = 1;
        qq.yy += 1;
        Q1.push(qq);
        qq.yy -= 1;
    }
}

// Поиск всех бонусов
void Ai::BonusSearch() {
    int BonusNow = 0;
    que qn = Q1.front();
    Q1.pop();
    while (BonusNow != ABonus){
        while (AMap->Arr[qn.xx][qn.yy].pack != '*'){
            AMap->Arr[qn.xx][qn.yy].ff = 1;
            Surround(qn);
            qn = Q1.front();
            Q1.pop();
        }
        AMap->Arr[qn.xx][qn.yy].pack = '+';
        BonusNow += 1;
        S.push(qn);
        while (AMap->Arr[qn.xx][qn.yy].point != 1){
            int fl = 0;
            if ((AMap->Arr[qn.xx - 1][qn.yy].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx - 1][qn.yy].down_wall == 0)) { fl = 1; }
            if ((AMap->Arr[qn.xx + 1][qn.yy].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy].down_wall == 0)) { fl = 2; }
            if ((AMap->Arr[qn.xx][qn.yy - 1].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy - 1].right_wall == 0)) { fl = 3; }
            if ((AMap->Arr[qn.xx][qn.yy + 1].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy].right_wall == 0)) { fl = 4; }
            switch (fl) {
            case (1) :
                qn.xx -= 1;
                S.push(qn);
                break;
            case (2):
                qn.xx += 1;
                S.push(qn);
                break;
            case (3) :
                qn.yy -= 1;
                S.push(qn);
                break;
            case (4) :
                qn.yy += 1;
                S.push(qn);
                break;
            }
        }
        while (S.size() != 0){
            Q2.push(S.top());
            S.pop();
        }
        while (Q1.size() != 0){
            Q1.pop();
        }
        qn = Q2.back();
        AMap->Nul();
    }
    AMap->Arr[AMap->exI][AMap->exJ].pack = '#';
}

// Поиск выхода
void Ai::ExitSearch(){
    que qn = Q2.back();
    while (AMap->Arr[qn.xx][qn.yy].pack != '#'){
        AMap->Arr[qn.xx][qn.yy].ff = 1;
        Surround(qn);
        qn = Q1.front();
        Q1.pop();
    }
    S.push(qn);
    while (AMap->Arr[qn.xx][qn.yy].point != 1) {
        int fl = 0;
        if ((AMap->Arr[qn.xx - 1][qn.yy].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx - 1][qn.yy].down_wall == 0)) { fl = 1; }
        if ((AMap->Arr[qn.xx + 1][qn.yy].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy].down_wall == 0)) { fl = 2; }
        if ((AMap->Arr[qn.xx][qn.yy - 1].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy - 1].right_wall == 0)) { fl = 3; }
        if ((AMap->Arr[qn.xx][qn.yy + 1].point == AMap->Arr[qn.xx][qn.yy].point - 1) && (AMap->Arr[qn.xx][qn.yy].right_wall == 0)) { fl = 4; }
        switch (fl) {
        case (1) :
            qn.xx -= 1;
            S.push(qn);
            break;
        case (2) :
            qn.xx += 1;
            S.push(qn);
            break;
        case (3) :
            qn.yy -= 1;
            S.push(qn);
            break;
        case (4) :
            qn.yy += 1;
            S.push(qn);
            break;
        }
    }
    while (S.size() != 0){
        Q2.push(S.top());
        S.pop();
    }
    while (Q1.size() != 0){
        Q1.pop();
    }
    AMap->Nul();
}

// Вызов методов для прохождения
void Ai::Exit(){
    BonusSearch();
    ExitSearch();
}

//Изменения лабиринта после 1 хода бота
void Ai::ExitDraw(){
    que qqq;
    qqq = Q2.front();
    Q2.pop();
    AMap->Arr[APla->xx][APla->yy].pack = ' ';
    APla->xx = qqq.xx;
    APla->yy = qqq.yy;
    AMap->Arr[AMap->exI][AMap->exJ].pack = '#';
    AMap->Arr[APla->xx][APla->yy].pack = 'x';
}
