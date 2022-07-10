#include "Game.h"

// Private init functions

void Game::initVariables() {
    
    /*
        @return void
        - 

    */


    this->window = nullptr;
    
    this->winnerBoard = "048,246,012,345,678,036,147,258";
    this->winnerPlayer = nullptr;

    this->boardPosition.x = 200;
    this->boardPosition.y = 250;
    this->sizeBoardField = { 70 };
    this->gold = { 1.2 };

   


}

void Game::initWindow() {

    this->videoMode.height = 400;
    this->videoMode.width = 400;
    
    this->window = new RenderWindow(this->videoMode, L"Kó³ko i Krzy¿yk", Style::Titlebar | Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initBoard() {

    Vector2f center = this->boardPosition;

    Vector2f pos1;
    pos1.x = center.x - (this->gold + 0.5) * this->sizeBoardField;
    pos1.y = center.y - (this->gold + 0.5) * this->sizeBoardField;
    Vector2f tempPos = pos1;


    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            this->field1.setPosition(tempPos.x, tempPos.y, this->sizeBoardField);
            this->board.push_back(this->field1);
            tempPos.x += this->gold * this->sizeBoardField;

        }
        tempPos.x = pos1.x;
        tempPos.y += this->gold * this->sizeBoardField;
    }
    
}

void Game::initPlayers() {

    RenderWindow* pole1;
    RenderWindow* pole2;

    // create new window to read name of player 1
    pole1 = new RenderWindow(VideoMode(400, 200), "player 1");
    player1 = new Player(setNameOfPlayer("player 1", "Wpisz imie gracza pierwszego", { 10,20 }, { 10, 50 }, pole1));
    pole1->close();
    player1->setColor(Color::Yellow);
    player1->setBackgroundRectangle(Color(255, 214, 77, 50),{0,0});

    // create new window to read name of player 2
    pole2 = new RenderWindow(VideoMode(400, 200), "player 2");
    player2 = new Player(setNameOfPlayer("player 2", "Wpisz imie gracza drugiego", { 10, 20 }, { 10, 50 }, pole2));
    pole2->close();
    player2->setColor(Color::Green);
    player2->setBackgroundRectangle(Color(100, 255, 25, 50),{200,0});

    // random sign of player
    char z = signDrawing();

    this->player1->setDrawSign(z);
    if (z == 'X') {
        this->player2->setDrawSign('O');
        this->ActivePlayer = this->player2;
    }
    else {
        this->player2->setDrawSign('X');
        this->ActivePlayer = this->player1;
    }



    delete pole1;
    delete pole2;
}

void Game::initFonts() {
    if (!this->font1.loadFromFile("Almendra-Regular.ttf"))
        cout << "Nie wczytano czcionki \n";
}

void Game::initTexts() {

    this->playerText1.setPosition(Vector2f(10,10));
    this->playerText1.setFillColor(this->player1->getColor());
    this->playerText1.setFont(this->font1);
    this->playerText1.setString("Player : \n"+this->player1->getName());

    this->playerText2.setPosition(Vector2f(300,10));
    this->playerText2.setFillColor(this->player2->getColor());
    this->playerText2.setFont(this->font1);
    this->playerText2.setString("Player : \n"+this->player2->getName());

    this->znak1.setPosition(Vector2f(this->videoMode.width/2-30, 10));
    this->znak1.setFillColor(this->player1->getColor());
    this->znak1.setFont(this->font1);
    this->znak1.setString(this->player1->getDrawSign());

    this->znak2.setPosition(Vector2f(this->videoMode.width / 2 + 30, 10));
    this->znak2.setFillColor(this->player2->getColor());
    this->znak2.setFont(this->font1);
    this->znak2.setString(this->player2->getDrawSign());

}

// Constructors / Descructors

Game::Game() {
    this->initVariables();
    this->initFonts();
    this->initWindow();
    this->initPlayers();
    this->initBoard();
    this->initTexts();

}

Game::~Game() {
    cout << "desctructor game";
    delete this->window;
}

// Functions

// Game loop function 

const bool Game::windowIsOpen() const {
    return this->window->isOpen();
}

// Event function
void Game::pollEvents() {

    while (this->window->pollEvent(e)) {

        switch (e.type)
        {
        case Event::Closed: {
            this->window->close();
            break;
        }
        case Event::MouseButtonPressed: {
            if (e.mouseButton.button == Mouse::Left)
                this->updateBoard();
            break;
        }

        default:
            break;
        }


    }

}

void Game::updateMousePositions() {

    // mouse position ralative to window
    this->mousePosWindow = Mouse::getPosition(*this->window);

    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);// check it
}

void Game::updateTexts() {
    if (this->winnerPlayer == this->player1) {
        this->playerText1.setString(this->player1->getName()+"\nwinner");
    }

    if(this->winnerPlayer == this->player2) {
        this->playerText2.setString(this->player2->getName() + "\nwinner");
    }

}

void Game::updateBoard() {

    // all fields
    // when left key mouse press
    if (Mouse::isButtonPressed(Mouse::Left)) {
        
        for (int i = 0; i < this->board.size(); i++) {

            if (this->board[i].square.getGlobalBounds().contains(this->mousePosView) && 
                (this->board[i].getSignChar() != 'X' && this->board[i].getSignChar() != 'O')
                ) {
                this->board[i].square.setFillColor(Color(108, 122, 137));
                this->board[i].sign.setFillColor(this->ActivePlayer->getColor());
                this->board[i].sign.setString(this->ActivePlayer->getDrawSign());
                this->checkIfWinner(this->ActivePlayer->getDrawSign());
                if (this->ActivePlayer == this->player1) {
                    this->ActivePlayer = this->player2;
                }
                else {
                    this->ActivePlayer = this->player1;
                }
                break;
            }

        }

    }
    
}


void Game::update() {

    /*
        @return void
        - waiting for events

        Update objects in game
    */

    this->pollEvents();
    if (this->winnerPlayer != this->player1 && this->winnerPlayer != player2) {

    
        this->updateMousePositions();

    
    }
    this->updateTexts();
}


void Game::renderTexts() {
    this->window->draw(playerText1);
    this->window->draw(playerText2);
    this->window->draw(znak1);
    this->window->draw(znak2);
    this->window->draw(this->ActivePlayer->getBackgroundRectangle());
}

void Game::renderBoard() {
    for (auto& e : this->board) {
        this->window->draw(e.getField());
        this->window->draw(e.getSign());
    }
}

void Game::render() {

    /*
        @return void
        - clear old frame
        - draw objects
        - display frame in window

        Render the game objects
    */

    // clear old frame
    this->window->clear(Color(100, 100, 100, 50));

    // draw game objects
    this->renderBoard();
    this->renderTexts();

    // display new frame
    this->window->display();

}

// others

char Game::signDrawing() {

    srand((unsigned)time(NULL));
    int n;
    n = (rand() % 2) + 1;

    if (n == 1) {
        return 'X';
    }
    else {
        return 'O';
    }


}

String Game::setNameOfPlayer(string p, string t, Vector2f posText, Vector2f posName, RenderWindow* pole) {

    Text name{};
    name.setPosition(posName);
    name.setFillColor(Color::Blue);
    name.setFont(font);

    Text cos{};
    cos.setPosition(posText);
    cos.setFillColor(Color::Blue);
    cos.setFont(font);
    cos.setString(t);

    string napis{};

    while (pole->isOpen()) {
        Event event;
        while (pole->pollEvent(event))
        {


            switch (event.type) {

                // window closed
            case Event::Closed: {
                pole->close();
                break;
            }
            case Event::TextEntered: {
                if (event.text.unicode < 128)
                    napis += static_cast<char>(event.text.unicode);
                name.setString(napis);
                break;

            }
            case Event::KeyPressed: {

                switch (event.key.code) {

                case Keyboard::Enter: {

                    return name.getString();
                    break;
                }

                default: {
                    break;
                }
                }
                break;
            }
            }
        }
        pole->clear();
        pole->draw(name);
        pole->draw(cos);
        pole->display();
    }


}

void Game::checkIfWinner(char z) {

    int licznik{ 0 };
    int a{};

    for (int i = 0; i < this->winnerBoard.length(); i++) {
        if (this->winnerBoard[i] == ',') {
            cout << "sprawdzone " << i << " li:" << licznik << "\n";
            licznik = 0;
        }
        else {
            a = (int)this->winnerBoard[i] - 48;
            if (board[a].getSign().getString()[0] == z) {
                cout << "trafione " << i << " li:" << licznik<< "\n";
                licznik++;
               
            }
            else {
                cout << " nie trafione " << i << " li:" << licznik << "\n";
                
            }

            if (licznik == 3) {
                this->winnerPlayer = ActivePlayer;
                break;
            }

        }

        
    }
}
