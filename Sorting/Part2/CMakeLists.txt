cmake_minimum_required(VERSION 3.8)
project(Part2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sorter.cpp Sorter.h FileHandler.cpp FileHandler.h)
add_executable(Part2 ${SOURCE_FILES})