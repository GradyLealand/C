cmake_minimum_required(VERSION 3.8)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Maze.cpp Maze.h)
add_executable(MazeSolver ${SOURCE_FILES})