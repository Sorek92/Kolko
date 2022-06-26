#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player{
public:
		string name;
		char draw_sign;
		Color color;


		Player();
		Player(string n);
		~Player();
		
		void setName(string n);
		void setDrawSign(char ds);
		void setColor(Color c);

		string getName();
		char getDrawSign();
		Color getColor();
};

