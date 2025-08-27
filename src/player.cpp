#include "player.h"

Player::Player(char sym) : symbol(sym) {}
HumanPlayer::HumanPlayer(char sym) : Player(sym) {}
AIPlayer::AIPlayer(char sym) : Player(sym) {}

char Player::getSymbol() const {
    return symbol;
}

std::pair<int,int> HumanPlayer::getMove(Board &board) {
    int row, col;

    while(true) {
        std::cout << "Player " << symbol << " enter row (1-3): ";
        std::cin >> row;
        std::cout << "Player " << symbol << " enter column (1-3): ";
        std::cin >> col;
        row--;
        col--;
        if (board.makeMove(row, col, symbol)) {
            return {row, col};
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}

std::pair<int,int> AIPlayer::getMove(Board & board) {
    std::srand(std::time(nullptr));
    int row, col;

    while(true) {
        row = std::rand() % BOARD_SIZE;
        col = std::rand() % BOARD_SIZE;
        if (board.makeMove(row, col, symbol)) {
            std::cout << "AI " << symbol << " moves: " << row << "," << col << std::endl;
            return {row, col};
        }
    }
}