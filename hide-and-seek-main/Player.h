#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{

private:
    int length;
    int width;
    int posX;
    int posY;
    int sceneLength;
    int sceneWidth;
    int score;
    bool listenArrowKeys;

public:
    Player(int l, int w, int posX, int posY, int sceneLength , int sceneWidth, bool isListeningArrowKeys);
    int getLength();
    int getWidth();
    int getArea();
    int getPosX();
    int getPosY();
    int getSceneLength();
    int getSceneWidth();
    int getScore();
    void setScore(int point);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
  
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

};
#endif // PLAYER_H
