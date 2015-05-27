#include "mazewidget.h"
#include <iostream>

MazeWidget::MazeWidget(QWidget *parent) : QWidget (parent){}

//Создание Лабиринта
void MazeWidget::CreateMaze(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bonuses){

    maze = new Lab(width,height,ixit,jxit,ist,jst,bonuses);
    maze->CreateLab();
    maze->bonusCreator();
    this->update();
}

//Перегрузка keyPressEvent для осуществления ходов
void MazeWidget::keyPressEvent(QKeyEvent *pressed){
    //Проверка - не пройден ли уже лабиринт
    if (flag == 0) {
        if (pressed->key() == Qt::Key_Up) {
            if (maze->Arr[maze->stI-1][maze->stJ].down_wall == 0) {
                if (maze->Arr[maze->stI-1][maze->stJ].pack == '*'){
                    maze->bbb -= 1;
                }
                maze->Arr[maze->stI][maze->stJ].pack = ' ';
                maze->stI -= 1;
                maze->Arr[maze->exI][maze->exJ].pack = '#';
                maze->Arr[maze->stI][maze->stJ].pack = 'x';
                repaint();
            }
        }
        if (pressed->key() == Qt::Key_Down) {
            if (maze->Arr[maze->stI][maze->stJ].down_wall == 0) {
                if (maze->Arr[maze->stI+1][maze->stJ].pack == '*'){
                    maze->bbb -= 1;
                }
                maze->Arr[maze->stI][maze->stJ].pack = ' ';
                maze->stI += 1;
                maze->Arr[maze->exI][maze->exJ].pack = '#';
                maze->Arr[maze->stI][maze->stJ].pack = 'x';
                repaint();
            }
        }
        if (pressed->key() == Qt::Key_Right) {
            if (maze->Arr[maze->stI][maze->stJ].right_wall == 0) {
                if (maze->Arr[maze->stI][maze->stJ+1].pack == '*'){
                    maze->bbb -= 1;
                }
                maze->Arr[maze->stI][maze->stJ].pack = ' ';
                maze->stJ += 1;
                maze->Arr[maze->exI][maze->exJ].pack = '#';
                maze->Arr[maze->stI][maze->stJ].pack = 'x';
                repaint();
            }
        }
        if (pressed->key() == Qt::Key_Left) {
            if (maze->Arr[maze->stI][maze->stJ-1].right_wall == 0) {
                if (maze->Arr[maze->stI][maze->stJ-1].pack == '*'){
                    maze->bbb -= 1;
                }
                maze->Arr[maze->stI][maze->stJ].pack = ' ';
                maze->stJ -= 1;
                maze->Arr[maze->exI][maze->exJ].pack = '#';
                maze->Arr[maze->stI][maze->stJ].pack = 'x';
                repaint();

            }
        }
        //проверка - если лабиринт пройден - флаг = 1
        if ((maze->bbb == 0) && (maze->stI == maze->exI) && (maze->stJ == maze->exJ)){
            flag = 1;
        }
    }
}

//Отрисовка
void MazeWidget::paintEvent(QPaintEvent*){
    QPainter p(this);


    for (int i = 0; i < maze->H - 1; ++i){
        for (int j = 0; j < maze->W - 1; ++j){
            p.setPen(QPen(Qt::black, 1, Qt::SolidLine));
            if (maze->Arr[i][j].right_wall == 1) {
                p.drawLine(j*10+10,i*10,j*10+10,i*10+10);
            }
            if (maze->Arr[i][j].down_wall == 1) {
                p.drawLine(j*10,i*10+10,j*10+10,i*10+10);
            }
            p.setPen(QPen(Qt::red, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::red, Qt::SolidPattern));
            if (maze->Arr[i][j].pack == '*'){
                p.drawEllipse(j*10+1, i*10+1, 8, 8);
            }
            p.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
            if (maze->Arr[i][j].pack == 'x'){
                p.drawEllipse(j*10+1, i*10+1, 8, 8);
            }
            p.setPen(QPen(Qt::green, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::green, Qt::SolidPattern));
            if (maze->Arr[i][j].pack == '#'){
                p.drawEllipse(j*10+1, i*10+1, 8, 8);
            }
        }
    }
}


//Запуск и работа бота
void MazeWidget::BotStart(){

    bot = new Ai(*maze, maze->bbb, maze->stI, maze->stJ);
    bot->Exit();
    que qqq;

    while (bot->Q2.size() != 0) {
        qqq = bot->Q2.front();
        bot->Q2.pop();
        maze->Arr[maze->stI][maze->stJ].pack = ' ';
        maze->stI = qqq.xx;
        maze->stJ = qqq.yy;
        maze->Arr[maze->exI][maze->exJ].pack = '#';
        maze->Arr[maze->stI][maze->stJ].pack = 'x';
        repaint();
        Sleep(500);
    }
}
