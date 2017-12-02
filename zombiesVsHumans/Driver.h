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
    World *world = new World(1);
};


#endif //ZOMBIESVSHUMANS_DRIVER_H
