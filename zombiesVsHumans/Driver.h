//
// Created by prog2100 on 28/11/17.
//

#ifndef ZOMBIESVSHUMANS_DRIVER_H
#define ZOMBIESVSHUMANS_DRIVER_H

#include <string>
#include "World.h"


class Driver {
public:
    void start();

private:
    const int NUM_SECONDS = 1;
    World *world = new World(1);
    bool gameOver;
    int days;
};


#endif //ZOMBIESVSHUMANS_DRIVER_H
