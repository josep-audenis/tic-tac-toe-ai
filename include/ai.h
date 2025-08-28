#ifndef AI_H
#define AI_H

#include <limits>
#include <utility>

#include "board.h"

int minmax(Board &board, int depth, bool is_maximizing, char ai_symbol, char human_symbol, int alpha, int beta);

std::pair<int,int> findBestMove(Board &board, char ai_symbol);

#endif