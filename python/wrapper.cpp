#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "board.h"
#include "player.h"
#include "game.h"
#include "ai.h"

namespace py = pybind11;

PYBIND11_MODULE(tictactoe, m) {
    m.doc() = "Tic Tac Toe C++ backend (logic + AI)";

    py::class_<Board>(m, "Board")
        .def(py::init<>())
        .def("make_move", &Board::makeMove)
        .def("is_full", &Board::isFull)
        .def("check_winner", &Board::checkWinner)
        .def("display", &Board::display)
        .def("get_cell", &Board::getCell)
        .def("undo_move", &Board::undoMove);

    py::class_<Player>(m, "Player");
    
    py::class_<HumanPlayer, Player>(m, "HumanPlayer")
        .def(py::init<char>())
        .def("get_symbol", &HumanPlayer::getSymbol);

    py::class_<AIPlayer, Player>(m, "AIPlayer")
        .def(py::init<char>())
        .def("get_move", &AIPlayer::getMove);

    py::class_<Game>(m, "Game")
        .def(py::init<Player*, Player*>())
        .def("play", &Game::play);
    
    m.def("findBestMove", &findBestMove, "Find the best move using Minmax");
}