#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game *game;
    game = new Game();


    while (game->window.isOpen())
    {
        

        Event event;
        while (game->window.pollEvent(event))
        {
 

            switch (event.type)
            {
                // window closed
            case Event::Closed:{
                game->window.close();
                break;
            }
            case Event::MouseButtonPressed: {
                game->checkClicked(event);
                
            }
            
            }
        }
        if (game->wygrany != NULL) {
            game->window.clear();
            Text wyg;
            wyg.setPosition(Vector2f(10, 10));
            wyg.setFillColor(Color::Red);
            wyg.setFont(game->font);
            string napo = "wygra³ gracz " + game->ActivePlayer->getDrawSign();
            wyg.setString(napo);
            game->window.draw(wyg);
            game->window.display();
            
        }else
            game->update();
    }

    game->~Game();

    

    return 0;
}