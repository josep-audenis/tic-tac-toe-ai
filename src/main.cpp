#include <iostream>

#include "game.h"
#include "player.h"

int main() {
    HumanPlayer p1('X');
    AIPlayer p2('O');
    Game game(&p1, &p2);
    game.play();
    return 0;
}