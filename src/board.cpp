#include "board.h"

Board::Board() {
    grid = std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));
}

bool Board::makeMove(int row, int col, char symbol) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || grid[row][col] != ' ') {
        return false;
    }
    grid[row][col] = symbol;
    return true;
}

bool Board::isFull() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (grid[i][j] == ' ') return false;
        }
    }
    return true;
}

char Board::checkWinner() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return grid[i][0];
        }
        if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return grid[0][i];
        }
    }

    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0];
    }
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2];
    }

    return ' ';
}

bool Board::winPossibility() const {    // Rethink approach :(

    std::vector<int> empty_row = std::vector<int>(3);
    std::vector<int> empty_col = std::vector<int>(3);
    int empty_diag_left = 0;
    int empty_diag_right = 0;

    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (grid[i][j] == ' ') {
                if (empty_row[i]++ > 1 || empty_col[j]++ > 1) {
                    return true;
                }
                if (i == j) {
                    if (empty_diag_left++ > 1) {
                        return true;
                    }
                }
                if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 &&  j == 0)) {
                    if (empty_diag_right++ > 1) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void Board::display() const {
    std::cout << std::endl;
    std::cout << "+---+---+---+" << std::endl << "|";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << grid[i][j] << " |";
        }
        if (i < 2) {
            std::cout << std::endl << "+---+---+---+" << std::endl << "|";
        }
    }
    std::cout << std::endl << "+---+---+---+" << std::endl << std::endl;
}