#include "World.h"
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
    if(this->world->getOrganism(xPos-1, yPos) == nullptr){
        world->setOrganism(xPos - 1, yPos, new Human(world, xPos - 1, yPos));
        this->world = nullptr;
    }
}

void Human::spawn() {

}