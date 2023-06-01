#pragma once
#include <iostream>
using namespace std;
class card {
	friend class board;
	friend class player;

private:
	string type;
	int value;
public:
	card() {
		type = "";
		value = 0;
	}
	card(string type, int value) {
		this->type = type;
		this->value = value;
	}
	int get_value() {
		return value;
	}
	string get_type() {
		return type;
	}
	bool operator >(const card& c) const {

		if ((type==c.type)&&(type=="parrot"||type=="naghshe"||type=="treasure"||type=="hokm"))
		{
			if (value > c.value)
			{
				return true;
			}
		}
		else
		{
			if (type == "hokm" && (c.type == "parrot" || c.type == "naghshe" || c.type == "treasure")) {
				return true;
			}
			if ((type == "queen" || type == "dozde" || type == "skull") && (c.type == "parrot" || c.type == "naghshe" || c.type == "treasure" || c.type == "hokm")) {
				return true;
			}
			if (type == "skull" && c.type == "dozde") {
				return true;
			}
			if (type == "skull" && c.type == "queen") {
				return true;
			}
			if (type == "queen" && c.type == "dozde") {
				return true;
			}
			
		}
		return false;
	}
	bool operator == (const card & c) const {
		if (type == "queen" && c.type == "queen") {
			return true;
		}
		if (type == "dozde" && c.type == "dozde")
		{
			return true;
		}
		if (type == "skull" && c.type == "skull")
		{
			return true;
		}
		if (type == "parrot" && c.type == "treasure")
		{
			return true;
		}
		if (type == "parrot" && c.type == "naghshe")
		{
			return true;
		}
		if (type == "treasure" && c.type == "treasure")
		{
			return true;
		}
		return false;
	}
};
