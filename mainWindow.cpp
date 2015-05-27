#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QWidget(parent)
{
    //Выделение памяти для главного виджета
    mainW = new MazeWidget;

    //Настройка кнопок
    Create->setText("Создать");
    Exit->setText("Выход");
    Bot->setText("Бот");
    Create->setFixedSize(70,20);
    Exit->setFixedSize(70,20);
    Bot->setFixedSize(70,20);
    Bot->setEnabled(false);
    
    //Настройка спинбоксов и заголовков
    height->setText("Высота");
    width->setText("Ширина");
    bonus->setText("Кол-во бонусов");

    lineH->setFixedSize(55,20);
    lineH->setMinimum(10);
    lineH->setMaximum(100);
    lineW->setFixedSize(55,20);
    lineW->setMinimum(10);
    lineW->setMaximum(100);
    lineB->setFixedSize(55,20);
    lineB->setMaximum(lineH->value()*lineW->value()/10);
    
    //Помещение виджетов в слои
    vertLayButtons->addWidget(Create);
    vertLayButtons->addWidget(Bot);
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
    
    //Коннекты
    connect(Create,SIGNAL(clicked()),this,SLOT(readSpinBox()));
    connect(Exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(Bot,SIGNAL(clicked()),this,SLOT(BotStart1()));
    connect(lineH,SIGNAL(valueChanged(int)),this,SLOT(MaxBonusesChange()));
    connect(lineW,SIGNAL(valueChanged(int)),this,SLOT(MaxBonusesChange()));

    //Задание главного слоя
    setLayout(mainLay);
}

//Вызов бота
void mainWindow::BotStart1(){
    Bot->setEnabled(false);
    emit mainW->BotStart();
}


mainWindow::~mainWindow(){}

//Чтение спинбоксов
void mainWindow::readSpinBox() {
    Create->setEnabled(false);
    int hh,ww,bb;
    hh = lineH->value() + 2;
    ww = lineW->value() + 2;
    bb = lineB->value();
    emit createClicked(hh,ww,bb);
}

//Вызов генератора лабиринта
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
    
    //Настройка поля после создания лабиринта
    Bot->setEnabled(true);
    mainW->setFocus();
    lineH->setVisible(false);
    lineW->setVisible(false);
    lineB->setVisible(false);
    height->setVisible(false);
    width->setVisible(false);
    bonus->setVisible(false);
}

//Изменения максимального кол-ва бонусов
void mainWindow::MaxBonusesChange(){
    lineB->setMaximum(lineH->value()*lineW->value()/10);
}
