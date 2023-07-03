#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include "card.h"
#include <qlist.h>
#include <QDataStream>
#include <QDateTime>

class player
{
public:
    player();
    QString get_usernameOpponent();
    void set_usernameOpponent(QString a);
    void set_playerCard(card c);
         player( const player&);
        QList<card>& get_playerCards();
        void set_winCard(card c) ;
        QList<card> &get_winCards();
        void delete_playCard();
        //start
        void set_start(int s);
        int get_start();
        //username
        void set_username(QString s);
        QString get_username();
        //password
        void set_password(QString s);
        QString get_password();
        //phone
        void set_phoneNumber(QString s);
        QString get_phoneNumber();
        //profile
        void set_profile(QString s);
        QString get_profile();
        //win
        void set_win(int s);
        int get_win();
        //lose
        void set_lose(int s);
        int get_lose();
        //predictWin
        void set_predict_win(int s);
        int get_predict_win();
        // dore game
        void set_turn(int s);
        int get_turn();
        //nobat
        void set_nobat(int n);
        int get_nobat();
        //time
        void set_time(int t);
        int get_time();
        //countCard
        void set_countCard(int n);
        int get_countCard();
        //takeWin
        void set_takeWin(int s);
        int & get_takeWin();
        //coin
        void set_coin(long int s);
        long int get_coin();
        //playedCard
        void set_playedCard(card c);
        card get_playedCard();
        void set_playcardOpponent(card a);
         card get_playcardOpponent();
         //stop
         int get_stop();
         void set_stop(int a);

        card get_stratCard();
        void set_StratCard(card a);
        void set_point(long int a);
        long int get_point();
        QString get_role();
        void set_role(QString a);
       void set_pointOpponent(int long a);
      long int get_pointOpponent();
        friend QTextStream &operator >>(QTextStream& in, player &p);
        friend QTextStream &operator <<(QTextStream& out, const player &p);
        ~player();
private:
     QString username;
    QString password;
    QString phoneNumber;
    QString profile;
    QString role;
    QString usernameOpponent;
  long int point;
  long int pointOpponent;
    long int coin;
    int win;
    int lose;
    int turn;
    int predict_win;
    int start;
    int takeWin;//dast hai borde
    int nobat; //nobat
    int countCard;
    int time;
    int stop;
    QList<card>playerCard;//card hai ke dare
    QList<card>winCard;//card hai borde
    card playedCard;//card bazi shode
    card startCard;
    card playcardOpponent;


};
extern QVector <player> filePlayer;
extern player gPlayer;
#endif // PLAYER_H
