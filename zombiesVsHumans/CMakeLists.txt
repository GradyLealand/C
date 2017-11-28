cmake_minimum_required(VERSION 3.8)
project(zombiesVsHumans)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Human.cpp Human.h Zombie.cpp Zombie.h Organism.cpp Organism.h World.cpp World.h Driver.cpp Driver.h)
add_executable(zombiesVsHumans ${SOURCE_FILES})