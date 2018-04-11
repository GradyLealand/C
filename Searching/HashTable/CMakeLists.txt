cmake_minimum_required(VERSION 3.8)
project(HashTable)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Hash.cpp Hash.h FileHandler.cpp FileHandler.h)
add_executable(HashTable ${SOURCE_FILES})