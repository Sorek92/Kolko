#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player{
	private:
		// player parameters
		string name;
		char draw_sign;
		Color color;
		RectangleShape backgroundRectangle;

	public:
		// constructors / descructors
		Player();
		Player(string name);
		~Player();
		
		// functions set
		void setName(string name);
		void setDrawSign(char drawSign);
		void setColor(Color color);
		void setBackgroundRectangle(Color color, Vector2f position);

		// functions get
		string getName();
		char getDrawSign();
		Color getColor();
		RectangleShape getBackgroundRectangle();
};

