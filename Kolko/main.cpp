#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <iostream>
#include "pole.h"

using namespace sf;
using namespace std;

int main()
{

    RenderWindow window(VideoMode(400, 400), L"Kó³ko i Krzy¿yk");

    Pole* p;

    p = new Pole[9];


    int tempX = 110;
    int tempY = 100;
    int k = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            p[k].ustaw_pozycje(tempX, tempY);
            tempX += 65;
            k++;
        }
        tempX = 110;
        tempY += 65;
    }




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            switch (event.type)
            {
                // window closed
            case sf::Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                p[0].sprawdz_klikniecie(event);
                p[1].sprawdz_klikniecie(event);
                p[2].sprawdz_klikniecie(event);
                p[3].sprawdz_klikniecie(event);
                p[4].sprawdz_klikniecie(event);
                p[5].sprawdz_klikniecie(event);
                p[6].sprawdz_klikniecie(event);
                p[7].sprawdz_klikniecie(event);
                p[8].sprawdz_klikniecie(event);
                //p[1].sprawdz(event);

            // we don't process other types of events
            default:
                break;
            }

        }




        window.clear();

        for (int i = 0; i < 9; i++) {
            window.draw(p[i].wczytaj_pole());
        }


        window.display();
    }

    p->~Pole();

    return 0;
}