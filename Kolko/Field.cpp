#include "Field.h"


using namespace std;

Field::Field() {

    cout << "konstructor pole" << endl;
    this->size = 60;
    this->color = Color(150, 50, 250);
    this->textColor = Color::Red;
    this->button = true;
    if (!this->font.loadFromFile("Almendra-Regular.ttf"))
        cout << "Nie wczytano czcionki \n";
    setField();

}

Field::~Field() {
    cout << " destructor pola" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Field::setField() {

    this->square.setSize(Vector2f(this->size, this->size));
    this->square.setFillColor(this->color);
    this->sign.setFont(this->font);
    this->sign.setFillColor(this->textColor);
    this->sign.setCharacterSize(20);
    this->sign.setString("");
}

void Field::setPosition(float x, float y, float z) {
    this->square.setPosition(Vector2f(x, y));
    this->sign.setPosition(Vector2f(x + 25, y + 20));
}

void Field::setSign(Event e) {


}

void Field::setButton(bool b) {
    this->button = b;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

RectangleShape Field::getField() {
    return this->square;
}


Text Field::getSign() {
    return this->sign;
}

bool Field::getButton() {
    return this->button;
}

char Field::getSignChar() {
    return this->sign.getString()[0];
}
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Field::checkClicked(Event e, char z) {

    int xB = e.mouseButton.x;
    int yB = e.mouseButton.y;
    int xK = this->square.getPosition().x;
    int yK = this->square.getPosition().y;
    if (xB >= xK && xB <= xK + 65 && yB >= yK && yB <= yK + 65) {
        
        if (this->sign.getString() == "" && this->button == true) {
            this->square.setFillColor(Color(100, 100, 100));
            this->sign.setString(z);
            this->button = false;
            return true;
        }
        else {
            return false;
        }
        
    }
    else {
        return false;
    }


}



