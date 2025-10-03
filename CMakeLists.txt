cmake_minimum_required(VERSION 3.8)
project(M2OEP)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP main.cpp game.cpp minesweeper.cpp balatro.cpp stats.cpp)

add_executable(Function_Testing testing.cpp minesweeper.cpp balatro.cpp game.cpp stats.cpp)