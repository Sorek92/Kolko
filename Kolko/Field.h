
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Field : public RectangleShape {
public:
    RectangleShape square;
    Color color;
    Text sign;
    Font font;
    int size;
    Color textColor;
    bool button;

    // construktor 
    Field();
    // destructor
    ~Field();

    // set 
    void setField();
    void setPosition(float, float, float);
    void setSign(Event e);
    void setButton(bool b);

    // get
    RectangleShape getField();
    Text getSign();
    bool getButton();
    char getSignChar();
    
    //others
    bool checkClicked(Event e, char z);


    

    
};
