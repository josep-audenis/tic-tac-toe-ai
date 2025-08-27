cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(tictactoe_lib
    src/board.cpp
    src/player.cpp
    src/game.cpp
    src/ai.cpp
)

add_executable(test_game test/main.cpp)
target_link_libraries(test_game tictactoe_lib)
