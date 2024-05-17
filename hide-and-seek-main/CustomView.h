#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "Player.h"

class CustomView : public QGraphicsView
{
public:
    CustomView(QWidget* parent = nullptr, Player* player1 = nullptr, Player* player2 = nullptr);

    void setPlayer1(Player* player);
    void setPlayer2(Player* player);

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Player* player1;
    Player* player2;
};

#endif // CUSTOMVIEW_H
