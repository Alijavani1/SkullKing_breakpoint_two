#pragma once
#include "board.h"
#include "card.h"
#include <list>
#include <vector>
#include "player.h"
class game {
private:
	int numberPlayer;
	int turnPlayer;
	int dore;
	board board;

public:
	void set_dore(int d) {
		dore = d;
	}
	int get_dore() {
		return dore;
	}

	void scoring(player &p) {
		int predict_win, takewin;
		list<card>winCard;
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
		list<card>::iterator it;
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
	void randomCard(player &p1,player&p2) {
		vector<card>allCards;
		allCards = board.get_allcard();
		srand(time(NULL));
		for (int i = 0; dore * 2 > i; i++) {
			int r = rand() % allCards.size();
			p1.set_playerCard(allCards[r]);
			allCards.erase(allCards.begin() + r);
			int z = rand() % allCards.size();
			p2.set_playerCard(allCards[z]);
			allCards.erase(allCards.begin() + z);
		}
	}
	player playerWin(player& p1,player &p2) {
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
	bool isValid(player& p1, player& p2) {
		list<card>allCardp1 = p1.get_playerCards();
		list<card>allCardp2 = p2.get_playerCards();
		card cardp1 = p1.get_playedCard();
		card cardp2 = p2.get_playedCard();
		if (p1.get_start() == 1) {
			if ((cardp1.get_type() == "parrot") && (cardp2.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "parrot") {
						return false;
					}
				}
			}
			if ((cardp1.get_type() == "naghshe") && (cardp2.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "naghshe") {
						return false;
					}
				}
			}
			if ((cardp1.get_type() == "treasure") && (cardp2.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "treasure") {
						return false;
					}
				}
			}

			if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "parrot" )) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}
			if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "naghshe")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}
			if ((cardp1.get_type() == "hokm") && (cardp2.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}

			if ((cardp1.get_type() == "parrot") && (cardp2.get_type() == "naghshe" || cardp2.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "parrot") {
						return false;
					}

				}
			}
			if ((cardp1.get_type() == "naghshe") && (cardp2.get_type() == "parrot" || cardp2.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "naghshe") {
						return false;
					}

				}
			}
			if ((cardp1.get_type() == "treasure") && (cardp2.get_type() == "parrot" || cardp2.get_type() == "naghshe")) {
				list<card>::iterator it;
				for (it = allCardp2.begin(); it != allCardp2.end(); it++) {
					if (it->get_type() == "treasure") {
						return false;
					}

				}
			}
		}

		else {
			if ((cardp2.get_type() == "parrot") && (cardp1.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "parrot") {
						return false;
					}
				}
			}
			if ((cardp2.get_type() == "naghshe") && (cardp1.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "naghshe") {
						return false;
					}
				}
			}
			if ((cardp2.get_type() == "treasure") && (cardp1.get_type() == "hokm")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "treasure") {
						return false;
					}
				}
			}

			if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "parrot")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}
			if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "naghshe")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}
			if ((cardp2.get_type() == "hokm") && (cardp1.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "hokm") {
						return false;
					}
				}
			}

			if ((cardp2.get_type() == "parrot") && (cardp1.get_type() == "naghshe" || cardp1.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "parrot") {
						return false;
					}

				}
			}
			if ((cardp2.get_type() == "naghshe") && (cardp1.get_type() == "parrot" || cardp1.get_type() == "treasure")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "naghshe") {
						return false;
					}

				}
			}
			if ((cardp2.get_type() == "treasure") && (cardp1.get_type() == "parrot" || cardp1.get_type() == "naghshe")) {
				list<card>::iterator it;
				for (it = allCardp1.begin(); it != allCardp1.end(); it++) {
					if (it->get_type() == "treasure") {
						return false;
					}

				}
			}
		}
		return true;
	}

};
