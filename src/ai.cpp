#include "ai.h"

int minmax(Board &board, int depth, bool is_maximizing, char ai_symbol, char human_symbol, int alpha, int beta){
    
    char winner = board.checkWinner();
    
    if (winner == ai_symbol) {
        return 10 - depth;
    }
    if (winner == human_symbol) {
        return depth - 10;
    }
    if (board.isFull()) return 0;
    
    if (is_maximizing) {
        int best_score = std::numeric_limits<int>::min();
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board.getCell(row, col) == ' ') {
                    board.makeMove(row, col, ai_symbol);
                    int score = minmax(board, depth + 1, false, ai_symbol, human_symbol, alpha, beta);

                    board.undoMove(row, col);
                    best_score = std::max(best_score, score);
                    alpha = std::max(alpha, best_score);
                    if (beta <= alpha) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = std::numeric_limits<int>::max();
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board.getCell(row, col) == ' ') {
                    board.makeMove(row, col, human_symbol);
                    int score = minmax(board, depth + 1, true, ai_symbol, human_symbol, alpha, beta);
                    board.undoMove(row, col);
                    best_score = std::min(best_score, score);
                    beta = std::min(beta, best_score);
                    if (beta <= alpha) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
}

std::pair<int,int> findBestMove(Board &board, char ai_symbol) {
    int best_score = std::numeric_limits<int>::min();
    std::pair<int,int> best_move = {-1, -1};
    char human_symbol = (ai_symbol == 'X') ? 'O' : 'X';

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board.getCell(row, col) == ' ') {
                board.makeMove(row, col, ai_symbol);
                int score = minmax(board, 0, false, ai_symbol, human_symbol, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                board.undoMove(row, col);
                if (score > best_score) {
                    best_score = score;
                    best_move = {row, col};
                }
            }
        }
    }
    return best_move;
}