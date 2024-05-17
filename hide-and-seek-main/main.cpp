#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "CustomView.h"
#include "Player.h"
#include "Ghost.h"
#include <QBrush>
#include <QColor>
#include <QPen>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 500, 500);
    scene.setBackgroundBrush(QBrush(QColor(0,0,0)));

    Player player1(40, 40, 0, 0, scene.sceneRect().width(), scene.sceneRect().height(), true);

    player1.setFlag(QGraphicsItem::ItemIsFocusable);
    player1.setFocus();
    scene.addItem(&player1);

    Player player2(40, 40, 460, 460, scene.sceneRect().width(), scene.sceneRect().height(), false);

    player2.setFlag(QGraphicsItem::ItemIsFocusable);
    player2.setFocus();
    scene.addItem(&player2);

    Ghost ghosts[10] = {
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2),
        Ghost(scene.sceneRect().width(), scene.sceneRect().height(), player1, player2)
    };

    for (int i = 0; i < 10; i++) {
        scene.addItem(&ghosts[i]);
    }

    QGraphicsView view(&scene);
    view.setInteractive(true);
    view.setFocus();

    QTimer timers[10];
    for (int i = 0; i < 10; i++) {
        QObject::connect(&timers[i], SIGNAL(timeout()), &ghosts[i], SLOT(randomMove()));
        timers[i].start(1000);
    }

    CustomView customView(nullptr, &player1, &player2);
    customView.setScene(&scene);
    customView.setViewport(&view);
    customView.show();

    return a.exec();
}
