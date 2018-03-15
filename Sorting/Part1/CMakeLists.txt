cmake_minimum_required(VERSION 3.8)
project(Part1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sorter.cpp Sorter.h Util.cpp Util.h)
add_executable(Part1 ${SOURCE_FILES})