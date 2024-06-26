#ifndef GAME_H
#define GAME_H
#include <QMainWindow>
#include "board.h"
#include "player.h"
#include "server.h"
#include "client.h"

class game
{
public:
    game();
    void set_dore(int d);
    int get_dore();
    void scoring();
    void randomCard();
    int playerWin();
    bool isValid();
    int howStart();
      ~game();
private:
    int numberPlayer;
    int turnPlayer;
    int dore;
    board board;
};

#endif // GAME_H
