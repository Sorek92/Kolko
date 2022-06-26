#include "Game.h"

Game::Game() {
    window.create(VideoMode(400,400), L"Kó³ko i Krzy¿yk");

    wygranePola = "048,246,012,345,678,036,147,258";

    loadPlayers();
    wczytaj_plansze();
    if (player1->draw_sign == 'O') {
        ActivePlayer = player1;
    }
    else {
        ActivePlayer = player2;
    }
}

Game::~Game() {
    cout << "desctructor game";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::update() {

    window.clear();
    window.draw(zawodnicy(player1, Vector2f(10,10)));
    window.draw(zawodnicy(player2, Vector2f(300, 10)));
    for (int i = 0; i < 9; i++) {
        window.draw(field[i].getField());
        window.draw(field[i].getSign());
    }
    window.display();

}

void Game::loadPlayers() {
    window.clear();
    pole1.create(VideoMode(400, 200), "player 1");
    player1 = new Player(setNameOfPlayer("player 1", "Wpisz imie gracza pierwszego", { 10,20 }, { 10, 50 }, &pole1));
    pole1.close();
    pole2.create(VideoMode(400, 200), "player 2");
    player2 = new Player(setNameOfPlayer("player 2", "Wpisz imie gracza drugiego", { 10, 20}, { 10, 50}, &pole2));
    pole2.close();

    char z = losuj();
    
    player1->setDrawSign(z);
    if (z == 'X') {
        player2->setDrawSign('O');
    }
    else {
        player2->setDrawSign('X');
    }


};

String Game::setNameOfPlayer(string p, string t, Vector2f posText, Vector2f posName, RenderWindow *pole) {

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


Text Game::zawodnicy(Player *player, Vector2f v) {

    Text zawodnik1;
    zawodnik1.setPosition(v);
    zawodnik1.setFillColor(Color::Blue);
    zawodnik1.setFont(font);
    zawodnik1.setString(player->getName());

    return zawodnik1;


}

void Game::wczytaj_plansze() {
    cout << "ustawianie pozyji \n";
    int tempX = 110;
    int tempY = 100;
    int k = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            field[k].setPosition(tempX, tempY);

            tempX += 65;
            k++;
        }
        tempX = 110;
        tempY += 65;
    }


}

char Game::losuj() {
    srand((unsigned)time(NULL));
    int n;
    n = (rand() % 2) + 1;
    cout << n << " ";

    if (n == 1) {
        return 'X';
    }
    else {
        return 'O';
    }


}

void Game::checkClicked(Event e) {

    for (int i = 0; i < 9; i++) {
        if (field[i].checkClicked(e, ActivePlayer->getDrawSign())) {
            sprawdzWygrana(ActivePlayer->getDrawSign());
            if (ActivePlayer == player1) {
                ActivePlayer = player2;
            }
            else {
                ActivePlayer = player1;
            }
            
        }
    }

}

void Game::sprawdzWygrana(char z) {

    int licznik {0};
    int a{};

    for (int i = 0; i < wygranePola.length(); i++) {
        if (wygranePola[i] == ',') {
            cout << "sprawdzone " << i << "\n";
            licznik = 0;
        }else{
            a = (int)wygranePola[i] - 48;
            if (field[a].getSign().getString()[0] == z) {
                cout << "trafione " << i << "\n";
                licznik++;
            }
            
        }

        if (licznik == 3) {
            wygrany = ActivePlayer;
            break;
        }
    }
}