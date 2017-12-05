//
// Created by prog2100 on 28/11/17.
//

#include <cstdlib>
#include "Zombie.h"

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
//    //pick a random direction to move and see if the space is free to move too
//    bool freeSpace = false;
//    bool humanFound = false;
//    int xChange, yChange, step, attempt = 0, humanCheck;
//    do
//    {
//
//        //check for humans
//        do
//        {
//            step = this->world->returnRandom(8);
//            if(step == 0){xChange = -1; yChange = -1;}
//            else if(step ==1){xChange = 0; yChange = -1;}
//            else if (step == 2){xChange = 1; yChange = -1;}
//            else if (step == 3){xChange = -1; yChange = 0;}
//            else if (step == 4){xChange = 1; yChange = 0;}
//            else if (step == 5){xChange = -1; yChange = 1;}
//            else if (step == 6){xChange = 0; yChange = 1;}
//            else if (step == 7){xChange = 1; yChange = 1;}
//            //check for human only if in bounds
//            if(this->xPos + xChange < 20 && this->xPos + xChange > 0 && this->yPos + yChange < 20 && this->yPos > 0 )
//            {
//                if(world->getOrganism(xPos + xChange, yPos + yChange) != nullptr)
//                {
//                    world->getOrganism(xPos + xChange, yPos + yChange);
//                    if (world->getOrganism(xPos + xChange, yPos + yChange)->getSpecies() == HUMAN)
//                    {
//                        humanFound = true;
//                    }
//                }
//            }
//            humanCheck++;
//        }while(!humanFound && humanCheck < 100 );
//
//        //if no humans move
//        if(!humanFound)
//        {
//            step = this->world->returnRandom(8);
//            if(step == 0){xChange = -1; yChange = -1;}
//            else if(step ==1){xChange = 0; yChange = -1;}
//            else if (step == 2){xChange = 1; yChange = -1;}
//            else if (step == 3){xChange = -1; yChange = 0;}
//            else if (step == 4){xChange = 1; yChange = 0;}
//            else if (step == 5){xChange = -1; yChange = 1;}
//            else if (step == 6){xChange = 0; yChange = 1;}
//            else if (step == 7){xChange = 1; yChange = 1;}
//            attempt++;
//            //if you cant find a free space after 100 attempts there are none, stay where you are
//            if (attempt == 100){this->stepsInTime +=1; this->moved = true; freeSpace = true;}
//        }
//
//
//        //if no human found move like this
//        if(!humanFound)
//        {
//            if(this->world->getOrganism(xPos + xChange, yPos + yChange) == nullptr){
//                //increase steps and starvation
//                this->stepsInTime += 1;
//                this->starvation += 1;
//                //check to see if the zombie is starved
//                if(this->starvation == 3)
//                {
//                    //kill the zomebie
//                    starveThisZombie();
//                }
//                else
//                {
//                    //if not starved move the zombie
//                    world->setOrganism(xPos + xChange, yPos + yChange, this);
//                    world->getOrganism(xPos + xChange, yPos + yChange)->setMoved(true);
//                    world->setOrganism(xPos , yPos, nullptr);
//                    //assign current cords to zombie
//                    this->xPos += xChange;
//                    this->yPos += yChange;
//                    this->x += xChange;
//                    this->y += yChange;
//                }
//                //move the organism
//
//                freeSpace = true;
//            }
//        }
//        else//if human found remove it then move zombie there
//        {
//            //step and reset starvation
//            this->stepsInTime += 1;
//            this->starvation = 0;
//            world->setOrganism(xPos + xChange, yPos + yChange, this);
//            world->getOrganism(xPos + xChange, yPos + yChange)->setMoved(true);
//            world->setOrganism(xPos , yPos, nullptr);
//            this->xPos += xChange;
//            this->yPos += yChange;
//            this->x += xChange;
//            this->y += yChange;
//            freeSpace = true;
//        }
//
//
//        attempt++;
//    }while(!freeSpace);
}

void Zombie::spawn() {

}

void Zombie::starveThisZombie() {
    world->setOrganism(xPos , yPos, nullptr);
}

int Zombie::getStarvation() {
    return 0;
}

void Zombie::setStarvation(int starveSteps) {

}
