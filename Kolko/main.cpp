#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    // Init game engine
    Game game;

    // Game loop - while window is open 
    while (game.windowIsOpen()) {

        // update 
        game.update();

        // render
        game.render();


    }
    

    return 0;
}