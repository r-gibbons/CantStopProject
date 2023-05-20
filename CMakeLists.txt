cmake_minimum_required(VERSION 3.21)
project(CantStop)

set(CMAKE_CXX_STANDARD 14)

add_executable(CantStop main.cpp tools.cpp tools.hpp Dice.cpp Dice.hpp Player.cpp Player.hpp Enums.hpp Enums.cpp Column.cpp Column.hpp Game.cpp Game.hpp Board.cpp Board.hpp Cell.hpp Cell.cpp BadPlayer.cpp BadPlayer.hpp BadChoice.hpp BadChoice.cpp)
