cmake_minimum_required(VERSION 3.8)
project(HTMLConverter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp convertMe.cpp Converter.cpp Converter.h)
add_executable(HTMLConverter ${SOURCE_FILES})