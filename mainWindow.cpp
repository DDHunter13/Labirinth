#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent)
{

    Create->setText("Создать");
    Exit->setText("Выход");

    height->setText("Высота");
    width->setText("Ширина");
    bonus->setText("Кол-во бонусов");

    Create->setFixedSize(70,20);
    Exit->setFixedSize(70,20);

    lineH->setFixedSize(55,20);
    lineH->setMinimum(2);
    lineH->setMaximum(100);
    lineW->setFixedSize(55,20);
    lineW->setMinimum(2);
    lineW->setMaximum(100);
    lineB->setFixedSize(55,20);
    lineB->setMaximum(100);

    vertLayButtons->addWidget(Create);
    vertLayButtons->addWidget(Exit);

    vertLayText->addWidget(height);
    vertLayText->addWidget(lineH);
    vertLayText->addWidget(width);
    vertLayText->addWidget(lineW);
    vertLayText->addWidget(bonus);
    vertLayText->addWidget(lineB);

    mainLay->addWidget(mainW);
    mainLay->addLayout(vertLayText);
    mainLay->addLayout(vertLayButtons);

    connect(Create,SIGNAL(clicked()),this,SLOT(readSpinBox()));
    connect(Exit,SIGNAL(clicked()),this,SLOT(close()));

    setLayout(mainLay);
}

mainWindow::~mainWindow()
{

}

void mainWindow::readSpinBox() {
    Create->setEnabled(false);
    int hh,ww,bb;
    hh = lineH->value() + 2;
    ww = lineW->value() + 2;
    bb = lineB->value() + 2;
    emit createClicked(hh,ww,bb);
}

void mainWindow::createClicked(int H, int W, int VB) {

    int startI = 1 + rand() % (H - 2);
    int startJ = 1 + rand() % (W - 2);

    int finishI = 1 + rand() % (H - 2);
    int finishJ = 1 + rand() % (W - 2);

    while ((finishI == startI) && (finishJ == startJ)) {
        finishI = 1 + rand() % (H - 2);
        finishJ = 1 + rand() % (W - 2);
    }
    mainW->setFixedSize(W*10,H*10);
    mainW->CreateMaze(W, H, finishI, finishJ, startI, startJ,VB);
}
