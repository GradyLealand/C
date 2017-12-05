#include <cstdlib>
#include "World.h"
#include <ctime>
#include "Organism.h"
#include "Human.h"
#include <random>
#include <vector>
#include <algorithm>


using namespace std;

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
    struct cord{

        int x;
        int y;
        cord(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };
    //create a vector with possible neghboring cords
    vector<cord> cords;
    cords.push_back(cord({-1, -1}));
    cords.push_back(cord(0, -1));
    cords.push_back(cord(1, -1));
    cords.push_back(cord(-1, 0));
    cords.push_back(cord(1, 0));
    cords.push_back(cord(-1, 1));
    cords.push_back(cord(0, 1));
    cords.push_back(cord(1, 1));
    //suffle the cords so the movement is random
    shuffle(cords.begin(), cords.end(), std::mt19937(std::random_device()()));
    for(int i = 0; i < cords.size(); i++)
    {
        if(this->xPos + cords[i].x >= 0 && this->xPos + cords[i].x < 20
           && this->yPos + cords[i].y >= 0 && this->yPos + cords[i].y < 20)
        {
            //if the spot is free then move
            if(world->getOrganism(xPos + cords[i].x, yPos + cords[i].y) == nullptr)
            {
                //increase steps
                this->stepsInTime += 1;
                //move the organism
                world->setOrganism(xPos + cords[i].x, yPos + cords[i].y, this);
                //assign it the previous steps +1
                world->getOrganism(xPos + cords[i].x, yPos + cords[i].y)->setMoved(true);
                world->setOrganism(xPos , yPos, nullptr);
                //assign current cords to human
                this->xPos += cords[i].x;
                this->yPos += cords[i].y;
                this->x += cords[i].x;
                this->y += cords[i].y;
                break;
            }
        }
    }
}

void Human::spawn() {

}