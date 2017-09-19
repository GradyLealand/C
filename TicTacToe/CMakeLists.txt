cmake_minimum_required(VERSION 3.8)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ticTacToe.cpp ticTacToe.h)
add_executable(TicTacToe ${SOURCE_FILES})