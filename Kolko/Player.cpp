#include "Player.h"

Player::Player() {
	name = "";
}

Player::Player(string n) {
	cout << "Construktor player : " + n + "\n";
	name = n;
};

Player::~Player() {
	cout << "destructor player : " + this->name + " \n";
};

////////////////////////////////////////////////////////////////////////////////////////////////////

void Player::setName(string n) {
	name = n;
};

void Player::setDrawSign(char ds) {
	draw_sign = ds;
};

void Player::setColor(Color c) {
	color = c;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

string Player::getName() {
	return name;
};

char Player::getDrawSign() {
	return draw_sign;
}

Color Player::getColor() {
	return color;
}

