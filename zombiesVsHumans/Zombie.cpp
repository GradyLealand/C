//
// Created by prog2100 on 28/11/17.
//

#include <cstdlib>
#include "Zombie.h"
#include <algorithm>

using namespace std;

Zombie::Zombie() {

}

Zombie::Zombie(World *world, int width, int height) : Organism(world, width, height) {
    this->world = world;
    this->xPos = width;
    this->yPos = height;
    this->x = width;
    this->y = height;
}

Zombie::~Zombie() {

}

speciesType Zombie::getSpecies() {
    return ZOMBIE;
}

void Zombie::move() {
    //a bool to chekc if the zombie has ben fed
    bool fed = false;

    //a structure to hold possible movements
    struct cord{

        int x;
        int y;
        cord(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };
    //create a vector with possible neighboring cords
    vector<cord> cords;
    cords.push_back(cord(-1, -1));
    cords.push_back(cord(-1, -0));
    cords.push_back(cord(-1, 1));
    cords.push_back(cord(0, -1));
    cords.push_back(cord(0, 1));
    cords.push_back(cord(1, -1));
    cords.push_back(cord(1, 0));
    cords.push_back(cord(1, 1));
    //shuffle the cords so the movement is random
    shuffle(cords.begin(), cords.end(), std::mt19937(std::random_device()()));

    //look for a human
    for (int i = 0; i < cords.size(); i++)
    {
        //only check if the value is inbounds
        if(this->xPos + cords[i].x >= 0 && this->xPos + cords[i].x < MAXROW
           && this->yPos + cords[i].y >= 0 && this->yPos + cords[i].y < MAXCOL)
        {
            //check to see if it is a nullptr
            if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y) != nullptr)
            {
                //if not a null pointer check to see if the organism is a human
                if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->getSpecies() == HUMAN)
                {
                    //add to steps
                    this->stepsInTime += 1;
                    //reset starvation
                    this->starvation = 0;
                    //move into the space
                    world->setOrganism(xPos + cords[i].x, yPos + cords[i].y, nullptr);
                    world->setOrganism(xPos + cords[i].x, yPos + cords[i].y, this);
                    world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->setMoved(true);
                    world->setOrganism(xPos, yPos, nullptr);
                    //assign current cords to zombie
                    this->xPos += cords[i].x;
                    this->yPos += cords[i].y;
                    this->x += cords[i].x;
                    this->y += cords[i].y;
                    //set fed to true
                    fed = true;
                    break;
                }
            }
        }
    }//end of loop to check for humans

    //if no humans were found then look for possible non feeding moves
    if(!fed){
        for (int i = 0; i < cords.size(); i++)
        {
            //only check if the value is inbounds
            if(this->xPos + cords[i].x >= 0 && this->xPos + cords[i].x < 20
               && this->yPos + cords[i].y >= 0 && this->yPos + cords[i].y < 20)
            {
                //check to see if it is a nullptr
                if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y) == nullptr)
                {

                    //add to starvation and movement
                    this->stepsInTime += 1;
                    this->starvation += 1;
                    //check to see if the zombie has starved
                    if(this->starvation >= STARVEZOMBIE)
                    {
                        this->starveThisZombie();
                        break;
                    }
                    else
                    {
                        //move into the space
                        world->setOrganism(xPos + cords[i].x, yPos + cords[i].y, this);
                        world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->setMoved(true);
                        world->setOrganism(xPos , yPos, nullptr);
                        //assign current cords to zombie
                        this->xPos += cords[i].x;
                        this->yPos += cords[i].y;
                        this->x += cords[i].x;
                        this->y += cords[i].y;
                        break;
                    }
                }
            }
        }
    }


}

void Zombie::spawn() {
//a structure to hold possible movements
    struct cord{

        int x;
        int y;
        cord(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };
    //create a vector with possible neighboring cords
    vector<cord> cords;
    cords.push_back(cord(-1, -1));
    cords.push_back(cord(-1, -0));
    cords.push_back(cord(-1, 1));
    cords.push_back(cord(0, -1));
    cords.push_back(cord(0, 1));
    cords.push_back(cord(1, -1));
    cords.push_back(cord(1, 0));
    cords.push_back(cord(1, 1));

    //loop through the vector to see if there is a free spot to spawn
    for (int i = 0; i < cords.size(); i++)
    {
        //only check if the value is inbounds
        if(this->xPos + cords[i].x >= 0 && this->xPos + cords[i].x < MAXCOL
           && this->yPos + cords[i].y >= 0 && this->yPos + cords[i].y < MAXROW)
        {
            //check to see if it is a nullptr
            if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y) != nullptr)
            {
                //check for a human
                if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->getSpecies() == HUMAN)
                {
                    world->setOrganism(xPos + cords[i].x, yPos + cords[i].y, new Zombie(world, xPos + cords[i].x, yPos + cords[i].y));
                    //set the new human to has spawned so it can re spawn this turn
                    world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->setHasSpawned(true);
                    break;
                }
            }
        }
    }

}

void Zombie::starveThisZombie() {
    world->setOrganism(xPos , yPos, nullptr);
}

int Zombie::getStarvation() {
    return 0;
}

void Zombie::setStarvation(int starveSteps) {

}
