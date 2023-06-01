#pragma once
#include <list>
using namespace std;
class board {
private:
	list<card>parrot;
	list<card>treasure;
	list<card>naghshe;
	list<card>hokm;
	list<card>queen;
	list<card>skull;
	list<card>dozde_daryayi;
	vector<card> allCards;
	
public:
	board() {
		for (int i = 0; 8 > i; i++) {
			card temp;
			temp.type = "parrot";
			temp.value = i + 1;
			parrot.push_back(temp);
		}
		for (int i = 0; 8 > i; i++) {
			card temp;
			temp.type = "treasure";
			temp.value = i + 1;
			treasure.push_back(temp);
		}
		for (int i = 0; 8 > i; i++) {
			card temp;
			temp.type = "naghshe";
			temp.value = i + 1;
			naghshe.push_back(temp);
		}
		for (int i = 0; 8 > i; i++) {
			card temp;
			temp.type = "hokm";
			temp.value = i + 1;
			hokm.push_back(temp);
		}
		for (int i = 0; 4 > i; i++) {
			card temp;
			temp.type = "queen";
			temp.value = -1;
			queen.push_back(temp);
		}
		for (int i = 0; 4 > i; i++) {
			card temp;
			temp.type = "skull";
			temp.value = -2;
			skull.push_back(temp);
		}
		for (int i = 0; 8 > i; i++) {
			card temp;
			temp.type = "dozde";
			temp.value = -3;
			dozde_daryayi.push_back(temp);
		}
		for (auto x : parrot)
			allCards.push_back(x);
		for (auto x : treasure)
			allCards.push_back(x);
		for (auto x : naghshe)
			allCards.push_back(x);
		for (auto x : hokm)
			allCards.push_back(x);
		for (auto x : queen)
			allCards.push_back(x);
		for (auto x : skull)
			allCards.push_back(x);
		for (auto x : dozde_daryayi)
			allCards.push_back(x);
	}
	list<card>get_parrotCard() {
		return parrot;
	}
	list<card>get_treasureCard() {
		return treasure;
	}
	list<card>get_naghsheCard() {
		return naghshe;
	}
	list<card>get_hokmCard() {
		return hokm;
	}
	list<card>get_queenCard() {
		return queen;
	}
	list<card>get_skullCard() {
		return skull;
	}
	list<card>get_dozdCard() {
		return dozde_daryayi;
	}
	vector<card>get_allcard() {
		return allCards;
	}
};
