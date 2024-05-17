// Ghost.h

#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Player.h"
#include <QGraphicsPixmapItem>

class Ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int sceneLength;
    int sceneWidth;
    int posX;
    int posY;
    bool isActive;
    Player *player1;
    Player *player2;
    QTimer* timer;

public:
    Ghost(int sceneLength, int sceneWidth, Player& player1, Player& player2);
    int getPosX();
    int getPosY();
    bool getIsActive();
    void setIsActive(bool control);
    bool active();


public slots:
    void randomMove();
};

#endif // GHOST_H

