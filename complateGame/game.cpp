#include "game.h"

game::game()
{
 dore=1;
}
void game:: set_dore(int d) {
        dore = d;
    }
    int game:: get_dore() {
        return dore;
    }
 int game:: howStart(){
     QList<card>parrotCard=board.get_parrotCard();
     srand(time(NULL));
     int r1 = rand() % 8;
     gPlayer.set_StratCard(parrotCard[r1]);
     int r2 = rand() % 8;
     while (r1==r2) {
          r2 = rand() % 8;
     }
     return r2;
}

void game:: randomCard() {
    if(gPlayer.get_turn()>1){
    gPlayer.delete_playCard();
    }
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
                  message=rand1.at(counter)+','+ message;
           }
         gserver.writeClient(message);
    }

        else{
            QString a=gclient.get_data();
             allCards = board.get_allcard();
            QStringList s = a.split(',');
            for(int i=0;i<s.size();i++){
                allCards[s[i].toInt()].set_type(" ");
            }

         for (int i = 0; dore * 2 > i; i++) {
            int r = rand() % allCards.size();
            while (allCards[r].get_type()==" ") {
                r = rand() % allCards.size();
            }
            gPlayer.set_playerCard(allCards[r]);
            allCards.erase(allCards.begin()+r);
         }


    }
}
    void game:: scoring() {
        int predict_win, takewin;
        QList<card>winCard;
        takewin = gPlayer.get_takeWin();
        predict_win = gPlayer.get_predict_win();
        winCard = gPlayer.get_winCards();

        long point =gPlayer.get_point();
        if (predict_win == takewin) {
            if (takewin == 0) {
                point =( dore * 10)+point;
            }
            else {
                point = (predict_win * 10)+point;
            }
        }
        else {
            if (predict_win == 0) {
                point = dore * (-10)+point;
            }
            else {
                point = (abs(predict_win-takewin) * (-10))+point;
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
        point += (countQ * 20) + (countS * 15) + (countD * 10);
        gPlayer.set_point(point);
    }


int game:: playerWin() {
        card pCard1 = gPlayer.get_playedCard();
        card pCard2 = gPlayer.get_playcardOpponent();
        if (pCard1 > pCard2) {
            gPlayer.set_winCard(pCard1);
            gPlayer.set_winCard(pCard2);
            int takewin = gPlayer.get_takeWin()+1;
            gPlayer.set_takeWin(takewin);
            gPlayer.set_start(1);
            gPlayer.set_nobat(1);
            return 1;
        }
        else {
            if (pCard1==pCard2)
            {
                if (gPlayer.get_start() == 1) {
                    gPlayer.set_winCard(pCard1);
                    gPlayer.set_winCard(pCard2);
                    int takewin = gPlayer.get_takeWin()+1;
                    gPlayer.set_takeWin(takewin);
                    gPlayer.set_start(1);
                    gPlayer.set_nobat(1);
                    return 1;
                }
                else{
                     gPlayer.set_start(0);
                     gPlayer.set_nobat(0);
                     return 0;
                }



            }
            else {
                gPlayer.set_start(0);
                gPlayer.set_nobat(0);
                return 0;

            }
        }
    }
   bool game:: isValid() {
        QList<card>allCardp1 = gPlayer.get_playerCards();
        card cardp1 = gPlayer.get_playedCard();
        card cardp2 = gPlayer.get_playcardOpponent();
        if (gPlayer.get_start() == 1) {
            return true;
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


