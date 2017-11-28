//
// Created by prog2100 on 28/11/17.
//

#include "Organism.h"
#include "World.h"

Organism::Organism() {

}

Organism::Organism(World *world, int xPos, int yPos) {

}

Organism::~Organism() {

}

bool Organism::getMoved() const {
    return false;
}

void Organism::setMoved(bool oneStep) {

}

bool Organism::getHasSpawned() {
    return false;
}

void Organism::setHasSpawned(bool hasSpawned) {

}

int Organism::getSteps() {
    return 0;
}

void Organism::setSteps(int aStepinTime) {

}

void Organism::setPosition(int x, int y) {

}
