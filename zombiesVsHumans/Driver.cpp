//
// Created by prog2100 on 28/11/17.
//

#include <iostream>
#include "Driver.h"
#include <unistd.h>



void Driver::start()
{
    double interval = 0.1;
    double counter = 0;
    clock_t this_time = clock();
    clock_t last_time = this_time;
    days = 0;
    gameOver = false;

    do{
        this_time = clock();
        counter += this_time - last_time;
        last_time = this_time;
        if(counter > interval * CLOCKS_PER_SEC)
        {
            counter -= interval * CLOCKS_PER_SEC;
            days++;
            gameOver = world->display(days);
            world ->step();
            world->spawnOrganisms();
        }


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
