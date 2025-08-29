#include "player.h"
#include "ai.h"

Player::Player(char sym) : symbol(sym) {}
HumanPlayer::HumanPlayer(char sym) : Player(sym) {}
AIPlayer::AIPlayer(char sym) : Player(sym) {}

char Player::getSymbol() const {
    return symbol;
}

std::pair<int,int> HumanPlayer::getMove(Board &board, bool terminal) {
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

std::pair<int,int> AIPlayer::getMove(Board & board, bool terminal = false) {
    std::pair<int,int> move = findBestMove(board, symbol);
    board.makeMove(move.first, move.second, symbol);
    if (terminal) {
        std::cout << "AI " << symbol << " moves: " << move.first << "," << move.second << std::endl;
    }
    return move;
}