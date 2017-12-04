#include <cstdlib>
#include "World.h"
#include <ctime>
#include "Organism.h"
#include "Human.h"

Human::Human() {

}

Human::Human(World *world, int xPos, int yPos) : Organism(world, xPos, yPos) {
    this->world = world;
    this->xPos = xPos;
    this->yPos = yPos;
    this->x = xPos;
    this->y = yPos;

}

Human::~Human() {

}

speciesType Human::getSpecies() {
    return HUMAN;
}

void Human::move() {
    srand((unsigned)time(0));
    //pick a random direction to move and see if the space is free to move too
    bool freeSpace = false;
    int xChange, yChange, step, attempt = 0;
    do
    {
        step = this->world->returnRandom(8);
        if(step == 0){xChange = -1; yChange = -1;}
        else if(step ==1){xChange = 0; yChange = -1;}
        else if (step == 2){xChange = 1; yChange = -1;}
        else if (step == 3){xChange = -1; yChange = 0;}
        else if (step == 4){xChange = 1; yChange = 0;}
        else if (step == 5){xChange = -1; yChange = 1;}
        else if (step == 6){xChange = 0; yChange = 1;}
        else if (step == 7){xChange = 1; yChange = 1;}
        //if you have tried to move 7 times already just stay where you are
        if (attempt == 100){xChange = 0; yChange = 0;}



        if(this->world->getOrganism(xPos + xChange, yPos + yChange) == nullptr){
            //get the setps before the organism moves
            int moves =  world->getOrganism(xPos, yPos)->getSteps();
            //move the organism
            world->setOrganism(xPos + xChange, yPos + yChange, new Human(world, xPos + xChange, yPos + yChange));
            //assign it the previous steps +1
            world->getOrganism(xPos + xChange, yPos + yChange)->setSteps(moves + 1);
            world->getOrganism(xPos + xChange, yPos + yChange)->setMoved(true);
            world->setOrganism(xPos , yPos, nullptr);
            freeSpace = true;

        }
        attempt++;
    }while(!freeSpace);
    //if it is not free pick a different spot


}

void Human::spawn() {

}