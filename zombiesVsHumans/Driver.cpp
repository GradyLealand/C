//
// Created by prog2100 on 28/11/17.
//

#include <iostream>
#include "Driver.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>



void Driver::start()
{
    days = 0;
    gameOver = false;
    do{
        days++;
        gameOver = world->display(days);
        world ->step();
        world->spawnOrganisms();
        sleep(1);

    }while (!gameOver);

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
