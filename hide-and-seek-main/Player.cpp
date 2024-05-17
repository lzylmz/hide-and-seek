// Player.cpp

#include "Player.h"
#include <QKeyEvent>

Player::Player(int l, int w, int posX, int posY, int sceneLength, int sceneWidth, bool isListeningArrowKeys)
    : length(l), width(w), posX(posX), posY(posY), sceneLength(sceneLength), sceneWidth(sceneWidth), score(0), listenArrowKeys(isListeningArrowKeys)
{
    setPos(posX, posY);
    setPixmap(QPixmap(":/images/startIcon.png"));
}

int Player::getLength()
{
    return length;
}

int Player::getWidth()
{
    return width;
}

int Player::getArea()
{
    return length * width;
}

int Player::getPosX()
{
    return posX;
}

int Player::getPosY()
{
    return posY;
}

int Player::getSceneLength()
{
    return sceneLength;
}

int Player::getSceneWidth()
{
    return sceneWidth;
}

int Player::getScore()
{
    return score;
}

void Player::setScore(int point)
{
    score = point;
}

void Player::moveLeft()
{
    if (posX > 0) {
        setPos(x() - 10, y());
        posX -= 10;
    }
}

void Player::moveRight()
{
    if (posX + length < sceneLength) {
        setPos(x() + 10, y());
        posX += 10;
    }
}

void Player::moveUp()
{
    if (posY > 0) {
        setPos(x(), y() - 10);
        posY -= 10;
    }
}

void Player::moveDown()
{
    if (posY + width < sceneWidth) {
        setPos(x(), y() + 10);
        posY += 10;
    }
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if(listenArrowKeys){
        switch (event->key()) {
        case Qt::Key_Left:
            moveLeft();
            setPixmap(QPixmap(":/images/leftMale"));
            break;
        case Qt::Key_Right:
            moveRight();
            setPixmap(QPixmap(":/images/rightMale"));
            break;
        case Qt::Key_Up:
            moveUp();
            setPixmap(QPixmap(":/images/upMale"));
            break;
        case Qt::Key_Down:
            moveDown();
            setPixmap(QPixmap(":/images/downMale"));
            break;
        default:
            setPixmap(QPixmap(":/images/startMale"));
            break;
        }
    }else{


        switch (event->key()) {
        case Qt::Key_A:
            moveLeft();
            setPixmap(QPixmap(":/images/femaleLeft"));
            break;
        case Qt::Key_D:
            moveRight();
            setPixmap(QPixmap(":/images/femaleRight"));
            break;
        case Qt::Key_W:
            moveUp();
            setPixmap(QPixmap(":/images/femaleUp"));
            break;
        case Qt::Key_S:
            moveDown();
            setPixmap(QPixmap(":/images/femaleDown"));
            break;
        default:
            setPixmap(QPixmap(":/images/femaleStart"));
            break;
        }

    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    setPixmap(QPixmap(":/images/startMale"));
    setPixmap(QPixmap(":/images/femaleStart"));
}

