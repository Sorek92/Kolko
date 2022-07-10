
#include "Field.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;


class Game :  public Field, public Player
{
	private:

		// Variables
		RenderWindow* window;
		VideoMode videoMode;
		Event e;

		// Mouse positions
		Vector2i mousePosWindow;
		Vector2f mousePosView;

		// Vector of board fields
		vector<Field> board;
		Field field1;

		// Fonts
		Font font1;

		// Texts
		Text playerText1;
		Text playerText2;
		Text znak1;
		Text znak2;

		// Board position and size
		Vector2f boardPosition;
		float sizeBoardField;
		float gold;

		// Private functions
		void initVariables();
		void initWindow();
		void initBoard();
		void initPlayers(); 
		void initFonts(); 
		void initTexts(); 


	public:
		
		// Variables

		Player *player1;
		Player *player2;
		Player *ActivePlayer;

		string winnerBoard;

		Player *winnerPlayer;

		// Contructors / Desctructors
		Game();
		virtual ~Game();


		// Functions
		const bool windowIsOpen() const;
		void pollEvents();
		
		void updateMousePositions();

		void updateTexts();
		void updateBoard();
		void update();

		void renderTexts();
		void renderBoard();
		void render();
		
		// others
		char signDrawing();
		String setNameOfPlayer(string p, string t, Vector2f posText, Vector2f posName, RenderWindow* pole);
		void checkIfWinner(char z);

};
