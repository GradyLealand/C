//
// Created by prog2100 on 28/11/17.
//

#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::Zombie(World *world, int width, int height) : Organism(world, width, height) {
    this->world = world;
    this->xPos = xPos;
    this->yPos = yPos;
    this->x = x;
    this->y = y;
}

Zombie::~Zombie() {

}

speciesType Zombie::getSpecies() {
    return ZOMBIE;
}

void Zombie::move() {

}

void Zombie::spawn() {

}

void Zombie::starveThisZombie() {

}

int Zombie::getStarvation() {
    return 0;
}

void Zombie::setStarvation(int starveSteps) {

}
