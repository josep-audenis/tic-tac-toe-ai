#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "board.h"
#include "player.h"

class Game {
    private:
        Board board;
        Player *player1;
        Player *player2;
        void switchTurns(Player* &current, Player* &other);

    public:
        Game(Player* p1, Player* p2);
        void play();
};

#endif