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
    return moved;
}

void Organism::setMoved(bool oneStep) {
    this->moved = oneStep;
}

bool Organism::getHasSpawned() {
    return false;
}

void Organism::setHasSpawned(bool hasSpawned) {

}

int Organism::getSteps() {
    return this->stepsInTime;
}

void Organism::setSteps(int aStepinTime) {
    this->stepsInTime = aStepinTime;

}

void Organism::setPosition(int x, int y) {
    this->xPos = x;
    this->yPos = y;
}
