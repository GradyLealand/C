//
// Created by prog2100 on 28/11/17.
//

#include <iostream>
#include "Driver.h"

void Driver::start()
{
    world->display();
    std::cout << "Hello, World!" << std::endl;

}

//build game map
    //populate 2d array with humans zombies and organisms

    //loop through array and place either zombie, human of organisms in grid

//move organisms
    //if organism is a zombie or a human
        //check surounding cells and determin movement rule

    //loop through array and count humans and combie to be displayed

    //check to see if all humans are dead

        //redraw map

        //if humans alive
            //continue loop

//if all humans are dead end game
