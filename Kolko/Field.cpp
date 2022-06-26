#include "Field.h"


using namespace std;

Field::Field() {

    cout << "konstructor pole" << endl;
    // this->kwadrat = new RectangleShape();
    // this->kwadrat->setSize(Vector2f(20,20));
    // this->kwadrat->setPosition(Vector2f(100,100));
    // this->kwadrat->setFillColor(Color(200,200,200));
    if (!font.loadFromFile("Almendra-Regular.ttf"));
    size = 60;
    color = Color(150, 50, 250);
    textColor = Color::Red;
    button = true;
    setField();

}

Field::~Field() {
    cout << " destructor pola" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Field::setField() {

    square.setSize(Vector2f(size, size));
    square.setFillColor(color);

    sign.setFillColor(textColor);
    sign.setCharacterSize(20);
    sign.setFont(font);
    sign.setString("");
}

void Field::setPosition(int x, int y) {
    square.setPosition(Vector2f(x, y));
    sign.setPosition(Vector2f(x + 25, y + 20));
}

void Field::setSign(Event e) {


}

void Field::setButton(bool b) {
    button = b;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

RectangleShape Field::getField() {
    return square;
}

Vector2f getPosition() {
    return Vector2f(20, 20);
}

Text Field::getSign() {
    return sign;
}

bool Field::getButton() {
    return button;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

bool Field::checkClicked(Event e, char z) {

    int xB = e.mouseButton.x;
    int yB = e.mouseButton.y;
    int xK = square.getPosition().x;
    int yK = square.getPosition().y;
    if (xB >= xK && xB <= xK + 65 && yB >= yK && yB <= yK + 65) {
        //cout << "dobrze" << kwadrat.getPosition().x << " = " << e.mouseButton.x  << endl;
        
        if (sign.getString() == "" && button == true) {
            square.setFillColor(Color(100, 100, 100));
            sign.setString(z);
            button = false;
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



