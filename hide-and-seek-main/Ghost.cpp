#include "Ghost.h"
#include "qpen.h"
#include "Player.h"
#include <random>
#include <QTimer>

Ghost::Ghost(int sceneLengthY , int sceneWidthX, Player &player1, Player &player2 ){
    setPixmap(QPixmap(":/images/ghost.png"));
    this->isActive = true;
    this->sceneLength =sceneLengthY;
    this->sceneWidth = sceneWidthX;
    this->player1 = &player1;
    this->player2 = &player2;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, sceneWidthX);
    int posX = distribution(gen);
    std::uniform_int_distribution<int> dis(0, sceneLengthY);
    int posY = dis(gen);
    setPos(posX,  posY);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(randomMove()));
    timer->start(100);

    this->posX = posX;
    this->posY = posY;
}


int Ghost::getPosX() {
    return posX;
}

int Ghost::getPosY() {
    return posY;
}

bool Ghost::getIsActive(){
    return (bool) this->isActive;
}
void Ghost::setIsActive(bool control){
    this->isActive = control;
}


bool Ghost::active(){
    bool isActive = true;

    //hayaletin durma algoritmasi
    if (player1->getPosX() - 50 < this->getPosX()
        &&  player1->getPosY() + 114 > this->getPosY()
        && player1->getPosX() + 164 > this->getPosX()
        &&  player1->getPosY() -50 < this->getPosY())
    {
        setVisible(true);
        isActive = false;
    }else
        setVisible(false);

    if (player1->getPosX() + 30 < this->getPosX()
        &&  player1->getPosY() + 64 > this->getPosY()
        && player1->getPosX() + 84 > this->getPosX()
        &&  player1->getPosY()  < this->getPosY() )
    {
        timer->stop();
        int point ;
        point = player1->getScore();
        point = point+1;
        player1->setScore(point);
    }

    return isActive;
}


void Ghost::randomMove(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);

    this->active();

    int randomNumber = distribution(gen);

    switch(randomNumber)
    {
    case 0:
        if (x()<=20 || y()<=20 )
            break;
        setPos(x()-10,y()-10);
        break;
    case 1:
        if (x()>=sceneWidth  || y()<=20 )
            break;
        setPos(x()+10,y()-10);
        break;
    case 2:
        if (x()>=sceneWidth  || y() >= sceneLength )
            break;
        setPos(x()+10,y()+10);
        break;
    case 3:
        if (x()<=20 || y() >= sceneLength )
            break;
        setPos(x()-10,y()+10);
        break;

        posX = x();
        posY = y();

if (!getIsActive()) {
                scene()->removeItem(this); // Remove the item from the scene
                delete this; // Delete the object
                return;}
    }}
