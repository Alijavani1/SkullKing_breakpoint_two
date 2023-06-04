#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include "board.h"
#include "player.h"

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    void set_dore(int d);
        int get_dore();
            void scoring(player &p);
            void randomCard(player &p1,player&p2);
                player playerWin(player& p1,player &p2);
                    bool isValid(player& p1, player& p2);
    ~game();

private:
    Ui::game *ui;
    int numberPlayer;
    int turnPlayer;
    int dore;
    board board;
};

#endif // GAME_H
