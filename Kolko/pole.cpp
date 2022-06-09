#include "pole.h"


using namespace std;

Pole::Pole() {

    cout << "konstructor pole" << endl;
    // this->kwadrat = new RectangleShape();
    // this->kwadrat->setSize(Vector2f(20,20));
    // this->kwadrat->setPosition(Vector2f(100,100));
    // this->kwadrat->setFillColor(Color(200,200,200));
    ustaw_pole();
}

Pole::~Pole() {
    cout << " destructor " << endl;
}


void Pole::ustaw_pole() {

    znak = '*';

    kwadrat.setSize(Vector2f(60, 60));
    kwadrat.setFillColor(Color(150, 50, 250));

    Font font;
    if (!font.loadFromFile("fonty/Almendra-Regular.otf"))

        Text text('X', font, 5);



    cout << "ustaw" << endl;
}

void Pole::ustaw_pozycje(int x, int y) {
    kwadrat.setPosition(Vector2f(x, y));
}

RectangleShape Pole::wczytaj_pole() {
    return kwadrat;
}

void Pole::sprawdz_klikniecie(Event e) {

    int xB = e.mouseButton.x;
    int yB = e.mouseButton.y;
    int xK = kwadrat.getPosition().x;
    int yK = kwadrat.getPosition().y;
    if (xB >= xK && xB <= xK + 65 && yB >= yK && yB <= yK + 65) {
        //cout << "dobrze" << kwadrat.getPosition().x << " = " << e.mouseButton.x  << endl;
        kwadrat.setFillColor(Color(100, 100, 100));
    }
    else {
        cout << "zle" << endl;
        kwadrat.setFillColor(Color(150, 50, 250));
    }
}
