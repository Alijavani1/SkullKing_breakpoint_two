#ifndef BOARD_H
#define BOARD_H
#include <QMainWindow>
#include "card.h"

namespace Ui {
class board;
}

class board : public QMainWindow
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = nullptr);
        QList<card>get_parrotCard();
        QList<card>get_treasureCard();
            QList<card>get_naghsheCard();
            QList<card>get_hokmCard();
            QList<card>get_queenCard();
            QList<card>get_skullCard();
            QList<card>get_dozdCard();
            QVector<card>&get_allcard();
    ~board();

private:
    Ui::board *ui;
    QList<card>parrot;
    QList<card>treasure;
    QList<card>naghshe;
    QList<card>hokm;
    QList<card>queen;
    QList<card>skull;
    QList<card>dozde_daryayi;
    QVector<card> allCards;
};

#endif // BOARD_H
