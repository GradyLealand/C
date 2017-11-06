cmake_minimum_required(VERSION 3.8)
project(Courses)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp Student.h)
add_executable(Courses ${SOURCE_FILES})