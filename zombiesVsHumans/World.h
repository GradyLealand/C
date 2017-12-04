//Header: World
#ifndef _WORLD_H
#define _WORLD_H

#include "Organism.h"

class Organism;//Superclass organism is an abstraction of an entity inside a world

//const int ARRAYSIZE = 20;//Default grid dimensions
const int MAXROW = 20;
const int MAXCOL = 20;
const int INITHUMANS = 10;//Initial population of humans
const int INITZOMBIES = 5;//Initial population of zombies
const int SPAWNHUMANS = 3;//A step in time when humans spawn
const int SPAWNZOMBIES = 8;//A step in time when zombies spawn
const int STARVEZOMBIE = 3;//A step in time when zombies starve

class World//Prototype of a world object
{
private:
    Organism *grid[MAXROW][MAXCOL];//Dynamic 2D array where objects are contained in memory

    //Private member methods
    void populateWorld();
    void setMovedToFalse();
    void moveOrganisms();
    void spawnOrganisms();

public:
    //Constructor(s), Destructor(s)
    World(int rand);
    virtual ~World();

    //Public member methods (For interface/driver)
    Organism *getOrganism(int x, int y) const;
    void setOrganism(int x,int y, Organism* thisOrganism);
    bool display() const;
    void displayForunix() const;
    void displayForWindows() const;
    void step();
    int returnRandom(int thisNumber) const;
    void resetMove();

    int count = 0;
};
#endif
//End Header: World
