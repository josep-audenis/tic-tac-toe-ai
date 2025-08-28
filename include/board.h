#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>

#define BOARD_SIZE 3

class Board {
    private:
        std::vector<std::vector<char>> grid;

    public:
        Board();
        bool makeMove(int row, int col, char symbol);
        void undoMove(int row, int col);

        bool isFull() const;
        bool winPossibility() const;
        char checkWinner() const;
        void display() const;
        char getCell(int row, int col) const;
};

#endif