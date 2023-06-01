#pragma once
#include <list>
#include "card.h"
class player {
private:
	string username;
	string password;
	string phoneNumber;
	string profile;
	long int coin;
	int win;
	int lose;
	int turn;
	int predict_win;
	int start;
	int takeWin;//dast hai borde
	list<card>playerCard;//card hai ke dare
	list<card>winCard;//card hai borde
	card playedCard;//card bazi shode
public:
	player() {
		turn = 0;
		predict_win = 0;
	}
	void set_playerCard(card c) {
		playerCard.push_back(c);
	}
	list<card>& get_playerCards() {
		return playerCard;
	}
	void set_winCard(card c) {
		winCard.push_back(c);
	}
	list<card> &get_winCards() {
		return winCard;
	}
	
	void delete_playCard() {
		list<card>::iterator it;
		for (it = playerCard.begin(); it != playerCard.end(); it++) {
			if (it->type == playedCard.get_type() && it->value == playedCard.get_value()) {
				playerCard.erase(it);
				break;
			}
		}
	}
//	card delete_playCard( int val) {
//	list<card>::iterator it;
//	return playerCard[val];
//}
	//start
	void set_start(int s) {
		start = s;
	}
	int get_start() {
		return start;
	}
	//username
	void set_username(string s) {
		username = s;
	}
	string get_username() {
		return username;
	}
	//password
	void set_password(string s) {
		password = s;
	}
	string get_password() {
		return password;
	}
	//phone
	void set_phoneNumber(string s) {
		phoneNumber = s;
	}
	string get_phoneNumber() {
		return phoneNumber;
	}
	//profile
	void set_profile(string s) {
		profile = s;
	}
	string get_profile() {
		return profile;
	}
	//win
	void set_win(int s) {
		win = s;
	}
	int get_win() {
		return win;
	}
	//lose
	void set_lose(int s) {
		lose = s;
	}
	int get_lose() {
		return lose;
	}
	//predictWin
	void set_predict_win(int s) {
		predict_win = s;
	}
	int get_predict_win() {
		return predict_win;
	}
	//takeWin
	void set_takeWin(int s) {
		takeWin = s;
	}
	int & get_takeWin() {
		return takeWin;
	}
	//coin
	void set_coin(long int s) {
		coin = s;
	}
	long int get_coin() {
		return coin;
	}
	//playedCard
	void set_playedCard(card c) {
		playedCard = c;
	}
	card get_playedCard() {
		return playedCard;
	}

};
