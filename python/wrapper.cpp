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
        .def("makeMove", &Board::makeMove)
        .def("isFull", &Board::isFull)
        .def("checkWinner", &Board::checkWinner)
        .def("display", &Board::display)
        .def("getCell", &Board::getCell)
        .def("undoMove", &Board::undoMove);

    py::class_<HumanPlayer>(m, "HumanPlayer")
        .def(py::init<char>())
        .def("getSymbol", &HumanPlayer::getSymbol);

    py::class_<AIPlayer>(m, "AIPlayer")
        .def(py::init<char>())
        .def("getMove", &AIPlayer::getMove);

    py::class_<Game>(m, "Game")
        .def(py::init<Player*, Player*>())
        .def("play", &Game::play);
    
    m.def("findBestMove", &findBestMove, "Find the best move using Minmax");
}