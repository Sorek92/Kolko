#include "Player.h"


						//----- constructors / descructors -----
Player::Player() {
	/*
		@
		- constructor of player name without parameters

		set default name of player = Guest
	*/

	this->name = "Guest";
}

Player::Player(string name) {
	/*
		@
		- constructor of player name with parameter n

		set name of player = n
	*/
	cout << "Construktor player : " + name + "\n";
	this->name = name;
};

Player::~Player() {
	/*
		@
		- descructor of player

		delete player
	*/

	cout << "destructor player : " + this->name + " \n";
};

						//----- functions set -----

void Player::setName(string n) {
	/*
		@return void
		- set of player name 
	*/

	this->name = n;
};

void Player::setDrawSign(char drawSign) {

	/*
		@return void
		- set of player sign
	*/

	this->draw_sign = drawSign;
};

void Player::setColor(Color color) {

	/*
		@return void
		- set of player color
	*/

	this->color = color;
}

void Player::setBackgroundRectangle(Color color, Vector2f position) {

	/*
		@return void
		- set of rectangle with color of player

		-set size
		-set position 
		-set color
	*/

	this->backgroundRectangle.setSize(Vector2f(200,100));
	this->backgroundRectangle.setPosition(position);
	this->backgroundRectangle.setFillColor(color);
}

						//----- functions get -----

string Player::getName() {

	/*
		@return string
		- return player name
	*/

	return name;
};

char Player::getDrawSign() {

	/*
		@return char
		- return player sign
	*/

	return draw_sign;
}

Color Player::getColor() {

	/*
		@return Color
		- return player color
	*/

	return this->color;
}

RectangleShape Player::getBackgroundRectangle() {

	/*
		@return RectangleShape
		- return background rectangle 
	*/

	return this->backgroundRectangle;
}
