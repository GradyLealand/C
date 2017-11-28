cmake_minimum_required(VERSION 3.8)
project(zombiesVsHumans)
set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Driver.cpp
        Human.cpp
        Human.h
        Organism.cpp
        Organism.h
        World.cpp
        World.h
        Zombie.cpp
        Zombie.h)

add_executable(zombiesVsHumans ${SOURCE_FILES})

target_link_libraries(zombiesVsHumans ${CURSES_LIBRARIES})