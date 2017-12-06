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

