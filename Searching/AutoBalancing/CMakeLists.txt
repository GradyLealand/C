cmake_minimum_required(VERSION 3.8)
project(AutoBalancing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FileHandler.cpp FileHandler.h Tree.cpp Tree.h)
add_executable(AutoBalancing ${SOURCE_FILES})