#include "game.h"

game::game()
{
 dore=0;
}
void game:: set_dore(int d) {
        dore = d;
    }
    int game:: get_dore() {
        return dore;
    }
 void game:: howStart(){
      QList<card>parrotCard=board.get_parrotCard();
        srand(time(NULL));
     if(gPlayer.get_role()=="server"){
             int r = rand() % 9;
             gPlayer.set_StratCard(parrotCard[r]);
             gserver.writeClient(QString::number(r));
     }
     else{
       int a=  gclient.get_data().toInt();
       int r = rand() % 9;
       while(a==r){
           r= rand() % 9;

       }
       gPlayer.set_StratCard(parrotCard[r]);
       gclient.writeClient(QString::number(r));
     }


 }

    void game:: randomCard() {
        QVector<card>allCards;
        allCards = board.get_allcard();
        srand(time(NULL));

        QVector<QString>rand1;
        if(gPlayer.get_role()=="server"){
         for (int i = 0; dore * 2 > i; i++) {
            int r = rand() % allCards.size();
            gPlayer.set_playerCard(allCards[r]);
           allCards.erase(allCards.begin() + r);
            rand1.push_back(QString::number(r));
    }
         QString message="";
         for(int counter=0;counter<rand1.length();counter++){
                  message=rand1.at(counter)+ message;
           }
         gserver.writeClient(message);
    }

        else{
            QString a=gclient.get_data();
         for (int i = 0; dore * 2 > i; i++) {
            int r = rand() % allCards.size();
            while(a[0]==QString::number(r)||a[1]==QString::number(r)||a[2]==QString::number(r)||a[3]==QString::number(r)
                  ||a[4]==QString::number(r)||a[5]==QString::number(r)||a[6]==QString::number(r)||a[7]==QString::number(r)
                  ||a[8]==QString::number(r)||a[9]==QString::number(r)||a[10]==QString::number(r)||a[11]==QString::number(r)
                  ||a[12]==QString::number(r)||a[13]==QString::number(r)||a[14]==QString::number(r)){
                int r = rand() % allCards.size();

            }
            gPlayer.set_playerCard(allCards[r]);
           allCards.erase(allCards.begin() + r);
            }

    }
    }
    void game:: scoring(player &p) {
        int predict_win, takewin;
        QList<card>winCard;
        takewin = p.get_takeWin();
        predict_win = p.get_predict_win();
        winCard = p.get_winCards();
        long int coin=0;
        if (predict_win == takewin) {
            if (takewin == 0) {
                coin = dore * 10;
            }
            else {
                coin = predict_win * 10;
            }
        }
        else {
            if (predict_win == 0) {
                coin = dore * (-10);
            }
            else {
                coin = predict_win * (-10);
            }
        }
        int countQ=0, countS=0, countD=0;
        QList<card>::iterator it;
        for (it = winCard.begin(); it != winCard.end(); it++) {
            if (it->get_type() == "queen") {
                countQ++;
            }
            if (it->get_type() == "skull") {
                countS++;
            }
            if (it->get_type() == "dozde") {
                countD++;
            }
        }
        coin += (countQ * 20) + (countS * 15) + (countD * 10);
        p.set_coin(coin);
    }
    player game:: playerWin(player& p1,player &p2) {
        card pCard1 = p1.get_playedCard();
        card pCard2 = p2.get_playedCard();
        if (pCard1 > pCard2) {
            p1.set_winCard(pCard1);
            p1.set_winCard(pCard2);
            int takewin = p1.get_takeWin()+1;
            p1.set_takeWin(takewin);
            p1.set_start(1);
            p2.set_start(0);
            return p1;
        }
        else {
            if (pCard1==pCard2)
            {
                if (p1.get_start() == 1) {
                    p1.set_winCard(pCard1);
                    p1.set_winCard(pCard2);
                    int takewin = p1.get_takeWin()+1;
                    p1.set_takeWin(takewin);
                    p1.set_start(1);
                    p2.set_start(0);
                    return p1;

                }
                if (p2.get_start() == 1) {
                    p2.set_winCard(pCard1);
                    p2.set_winCard(pCard2);
                    int takewin = p2.get_takeWin()+1;
                    p2.set_takeWin(takewin);
                    p2.set_start(1);
                    p1.set_start(0);
                    return p2;

                }
            }
            else {
                p2.set_winCard(pCard1);
                p2.set_winCard(pCard2);
                int takewin = p2.get_takeWin()+1;
                p2.set_takeWin(takewin);
                p2.set_start(1);
                p1.set_start(0);
                return p2;

            }
        }
    }
    bool game:: isValid(player& p1, player& p2) {
        QList<card>allCardp1 = p1.get_playerCards();
        QList<card>allCardp2 = p2.get_playerCards();
        card cardp1 = p1.get_playedCard();
        card cardp2 = p2.get_playedCard();
        if (p1.get_start() == 1) {
            if ((cardp1.get_type() == "parrot") && (cardp2.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "parrot") {
                        return false;
                    }
                }
            }
            if ((cardp1.get_type() == "naghshe") && (cardp2.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "naghshe") {
                        return false;
                    }
                }
            }
            if ((cardp1.get_type() == "treasure") && (cardp2.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "treasure") {
                        return false;
                    }
                }
            }

            if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "parrot" )) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }
            if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "naghshe")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }
            if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }

            if ((cardp1.get_type() == "parrot") && (cardp2.get_type() == "naghshe" || cardp2.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "parrot") {
                        return false;
                    }

                }
            }
            if ((cardp1.get_type() == "naghshe") && (cardp2.get_type() == "parrot" || cardp2.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "naghshe") {
                        return false;
                    }

                }
            }
            if ((cardp1.get_type() == "treasure") && (cardp2.get_type() == "parrot" || cardp2.get_type() == "naghshe")) {
                QList<card>::iterator it;
                for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
                    if (it->get_type() == "treasure") {
                        return false;
                    }

                }
            }
        }

        else {
            if ((cardp2.get_type() == "parrot") && (cardp1.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "parrot") {
                        return false;
                    }
                }
            }
            if ((cardp2.get_type() == "naghshe") && (cardp1.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "naghshe") {
                        return false;
                    }
                }
            }
            if ((cardp2.get_type() == "treasure") && (cardp1.get_type() == "hokm")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "treasure") {
                        return false;
                    }
                }
            }

            if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "parrot")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }
            if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "naghshe")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }
            if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "hokm") {
                        return false;
                    }
                }
            }

            if ((cardp2.get_type() == "parrot") && (cardp1.get_type() == "naghshe" || cardp1.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "parrot") {
                        return false;
                    }

                }
            }
            if ((cardp2.get_type() == "naghshe") && (cardp1.get_type() == "parrot" || cardp1.get_type() == "treasure")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "naghshe") {
                        return false;
                    }

                }
            }
            if ((cardp2.get_type() == "treasure") && (cardp1.get_type() == "parrot" || cardp1.get_type() == "naghshe")) {
                QList<card>::iterator it;
                for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
                    if (it->get_type() == "treasure") {
                        return false;
                    }

                }
            }
        }
        return true;
    }
    game::~game(){
    }
    game game1;


