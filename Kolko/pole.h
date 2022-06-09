
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Pole : public RectangleShape {
public:
    RectangleShape kwadrat;
    char znak;

    // konstruktor 
    Pole();
    // destruktor
    ~Pole();

    // ustawienie w³asciwosci pola
    void ustaw_pole();

    // ustawienie pozycji pola
    void ustaw_pozycje(int, int);

    // zwrocenie pola
    RectangleShape wczytaj_pole();

    // sprawdzenie klikniecia
    void sprawdz_klikniecie(Event e);

};
