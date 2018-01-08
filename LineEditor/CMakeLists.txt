cmake_minimum_required(VERSION 3.8)
project(LineEditor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FileHandler.cpp FileHandler.h Comands.cpp Comands.h MyLinkedList.cpp MyLinkedList.h Node.cpp Node.h)
add_executable(LineEditor ${SOURCE_FILES})