//
// Created by prog2100 on 28/11/17.
//

#include "World.h"
#include "Zombie.h"
#include "Human.h"
#include <iostream>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#include <unistd.h>

using namespace std;

void World::populateWorld() {
    srand(time(nullptr)); //https://stackoverflow.com/questions/22240683/random-number-generator-always-picks-the-same-number
    int humans = 0;
    int zombies = 0;
    do
    {
        int row = returnRandom(MAXROW);
        int col = returnRandom(MAXCOL);
        if(grid[row][col] == nullptr)
        {
            setOrganism(row, col, new Human(this, row, col));
            humans++;
        }

    }while (humans < INITHUMANS);

    do
    {
        int row = returnRandom(MAXROW);
        int col = returnRandom(MAXCOL);
        if(grid[row][col] == nullptr)
        {
            setOrganism(row, col, new Zombie(this, row, col));
            zombies++;
        }

    }while (zombies < INITZOMBIES);


}

void World::setMovedToFalse() {

}

void World::moveOrganisms() {

}

void World::spawnOrganisms() {

}

World::World(int rand) {
    populateWorld();
}

World::~World() {

}

Organism *World::getOrganism(int x, int y) const {

    return grid[x][y];

}

void World::setOrganism(int x, int y, Organism *thisOrganism) {
    grid[x][y] = thisOrganism;
}

bool World::display(int days) const {
    int r = 0; //row
    int c = 0; //column
    //have the humans gone extinct
    bool gameOver = false;

    //how many zombies and humans are there. reset at the beginning of each display loop
    int hNum = 0;
    int zNum = 0;
    do
    {
        do
        {
            if (grid[r][c] != nullptr)
            {
                if (grid[r][c]->getSpecies() == ZOMBIE)//check if equal to a zombie
                {
                    zNum++;
                    cout << GREEN << "[Z]" << RESET;
                }
                else if(grid[r][c]->getSpecies() == HUMAN)//check if equal to a human
                {
                    hNum++;
                    cout <<BLUE << "[H]" << RESET;
                }
            }
            else//if neither
            {
                cout << "[ ]";
            }
            c++;
        }while(c < MAXCOL);
        cout << endl;
        r++;
        c = 0;
    }while(r < MAXROW);

    //display stats
    cout << "Day: " << days << "   Humans: " << hNum << "   Zombies: " << zNum << endl;
    if (hNum == 0)
    {

        cout << "extinction happened after " << days << " days" << endl;
        return true;
    }else if(zNum)
    return false;

}//end display

void World::displayForunix() const {

}

void World::displayForWindows() const {

}

void World::step() {
    //reset movement of all organisms
    resetMove();

    for (int i = 0; i < MAXCOL; i++)
    {
        for (int j = 0; j < MAXROW; j++)
        {
            if(grid[i][j] != nullptr)
            {
                //make sure the organism has not moved this turn
                if(!grid[i][j]->getMoved())
                {
                    grid[i][j]->move();
                }

            }
        }
    }
}

void World::resetMove()
{
    for (int i = 0; i < MAXCOL; i++)
    {
        for (int j = 0; j < MAXROW; j++)
        {
            if(grid[i][j] != nullptr)
            {

                grid[i][j]->setMoved(false);
            }
        }
    }
}
int World::returnRandom(int thisNumber) const {
    return rand() % thisNumber;
}
