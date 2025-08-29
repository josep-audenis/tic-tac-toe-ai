#include "game.h"

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

void Game::switchTurns(Player* &current, Player* &other) {
    Player* temp = current;
    current = other;
    other = temp;
}

void Game::play() {
    Player* current = player1;
    Player* other = player2;

    board.display();
    while(true) {
        std::pair<int, int> current_move;
        current_move = current->getMove(board, true);
            
        board.display();

        char winner = board.checkWinner();
        if (winner != ' ') {
            std::cout << "Player " << winner << " wins!" << std::endl;
            break;
        }
        if (board.isFull() /*|| !board.winPossibility()*/) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }
        switchTurns(current, other);
    }
}