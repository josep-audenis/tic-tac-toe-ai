cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

add_library(tictactoe_lib
    src/board.cpp
    src/player.cpp
    src/game.cpp
    src/ai.cpp
)

set_target_properties(tictactoe_lib PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(test_game test/main.cpp)
target_link_libraries(test_game tictactoe_lib)

find_package(Python 3.11 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(tictactoe python/wrapper.cpp)
target_link_libraries(tictactoe PRIVATE tictactoe_lib pybind11::module)

set_target_properties(tictactoe PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

set_target_properties(tictactoe PROPERTIES PREFIX "" SUFFIX ".so")
