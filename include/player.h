#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "board.h"

class Player {
    protected:
        char symbol;
    public:
        Player(char sym);
        virtual std::pair<int,int> getMove(Board &board, bool terminal) = 0;
        char getSymbol() const;
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(char sym);
        std::pair<int,int> getMove(Board &board, bool terminal) override;
};

class AIPlayer : public Player {
    public:
        AIPlayer(char sym);
        std::pair<int,int> getMove(Board &board, bool terminal) override;
};

#endif