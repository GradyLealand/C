cmake_minimum_required(VERSION 3.8)
project(HTMLConverter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp convertMe.cpp converter.cpp converter.h)
add_executable(HTMLConverter ${SOURCE_FILES})