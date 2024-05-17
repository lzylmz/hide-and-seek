#include "CustomView.h"

CustomView::CustomView(QWidget* parent, Player* player1, Player* player2)
    : QGraphicsView(parent), player1(player1), player2(player2)
{
}

void CustomView::keyPressEvent(QKeyEvent* event)
{
    if (player1 && player2) {
        player1->keyPressEvent(event); // player1'in klavye olaylarını yakalama
        player2->keyPressEvent(event); // player2'nin klavye olaylarını yakalama
    }
    else {
        QGraphicsView::keyPressEvent(event);
    }
}

void CustomView::setPlayer1(Player* player)
{
    player1 = player;
}

void CustomView::setPlayer2(Player* player)
{
    player2 = player;
}
