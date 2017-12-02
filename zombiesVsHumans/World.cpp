//
// Created by prog2100 on 28/11/17.
//

#include "World.h"
#include "Zombie.h"
#include <iostream>

using namespace std;

void World::populateWorld() {
    Zombie zom = new Zombie(grid[5][5], 5, 5);

}

void World::setMovedToFalse() {

}

void World::moveOrganisms() {

}

void World::spawnOrganisms() {

}

World::World(int rand) {

}

World::~World() {

}

Organism *World::getOrganism(int x, int y) const {
    return nullptr;
}

void World::setOrganism(int x, int y, Organism *thisOrganism) {

}

void World::display() const {
    int r = 0; //row
    int c = 0; //column

    do
    {
        do
        {
            if (grid[r][c] != nullptr)
            {
                if (grid[r][c]->getSpecies() == ZOMBIE)//check if equal to a zombie
                {
                    cout << "Z";
                }
                else if(grid[r][c]->getSpecies() == HUMAN)//check if equal to a human
                {
                    cout << "H";
                }
            }
            else//if neither
            {
                cout << "-";
            }
            c++;
        }while(c < MAXCOL);
        cout << endl;
        r++;
        c = 0;
    }while(r < MAXROW);

}

void World::displayForunix() const {

}

void World::displayForWindows() const {

}

void World::step() {

}

int World::returnRandom(int thisNumber) const {
    return 0;
}