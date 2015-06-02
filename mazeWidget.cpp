#include "mazewidget.h"
#include <iostream>


MazeWidget::MazeWidget(QWidget *parent) : QWidget (parent){}


//Создание Лабиринта
void MazeWidget::CreateMaze(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bonuses){

    maze = new Lab(width,height,ixit,jxit,ist,jst,bonuses);
    player = new Player(maze,ist,jst);
    maze->CreateLab();
    maze->bonusCreator();
    this->update();
}

//Перегрузка keyPressEvent для осуществления ходов
void MazeWidget::keyPressEvent(QKeyEvent *pressed){
    //Проверка - не пройден ли уже лабиринт
    if (flag == 0) {
        if (pressed->key() == Qt::Key_Up) {
            player->MoveUp();
            repaint();
        }
        if (pressed->key() == Qt::Key_Down) {
            player->MoveDown();
            repaint();
        }
        if (pressed->key() == Qt::Key_Right) {
            player->MoveRight();
            repaint();
        }
        if (pressed->key() == Qt::Key_Left) {
            player->MoveLeft();
            repaint();
        }
        //проверка - если лабиринт пройден - флаг = 1
        if ((maze->bbb == 0) && (player->xx == maze->exI) && (player->yy == maze->exJ)){
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
            if ((maze->Arr[i][j].pack == '*') || (maze->Arr[i][j].pack == '+')){
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

    bot = new Ai(maze, maze->bbb, player->xx, player->yy, player);
    bot->Exit();
    emit BotMove();
}

//Единичный ход бота
void MazeWidget::BotMove(){
    if (bot->Q2.size() != 0){
        bot->ExitDraw();
        repaint();
    }
}
