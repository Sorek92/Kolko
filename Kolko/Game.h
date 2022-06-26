
#include "Field.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;


class Game : public RenderWindow, public Field, public Player
{
	public:
		RenderWindow window;
		RenderWindow pole1;
		RenderWindow pole2;

		Game();
		~Game();

		Field field[9];
		Player *player1;
		Player *player2;

		Player *ActivePlayer;

		string wygranePola;

		Player *wygrany;

		void update();

		void loadPlayers();
		char losuj();
		String setNameOfPlayer(string p, string t, Vector2f posText, Vector2f posName, RenderWindow *pole);
		Text zawodnicy(Player *p, Vector2f v);

		void wczytaj_plansze();
		void ustaw_pozycje(Vector2f pos);
		void checkClicked(Event e);
		void sprawdzWygrana(char z);
};
