#include "World.h"
#include "Organism.h"
#include "Human.h"

Human::Human() {

}

Human::Human(World *world, int xPos, int yPos) : Organism(world, xPos, yPos) {

}

Human::~Human() {

}

speciesType Human::getSpecies() {
    return ZOMBIE;
}

void Human::move() {

}

void Human::spawn() {

}