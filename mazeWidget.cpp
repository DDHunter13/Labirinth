#include "mazewidget.h"

MazeWidget::MazeWidget(QWidget *parent) : QWidget (parent)
{

}

void MazeWidget::CreateMaze(const int width, const int height, const int ixit, const int jxit, const int ist, const int jst, const int bonuses){
    maze = new Lab(width,height,ixit,jxit,ist,jst);
    maze->CreateLab();
    maze->bonusCreator(bonuses);
}

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
                p.drawEllipse(j*10+1, i*10+1, 7, 7);
            }
            p.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
            if (maze->Arr[i][j].pack == 'x'){
                p.drawEllipse(j*10+1, i*10+1, 7, 7);
            }
            p.setPen(QPen(Qt::green, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::green, Qt::SolidPattern));
            if (maze->Arr[i][j].pack == '#'){
                p.drawEllipse(j*10+1, i*10+1, 7, 7);
            }
        }
    }

}
