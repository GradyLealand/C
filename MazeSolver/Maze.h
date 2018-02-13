//
// Created by prog2100 on 11/02/18.
//

#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H

#include <string>
#include "StackNode.h"
#include "Stack.h"

using namespace std;


class Maze {
private:
    char** mazeArray;
    int rows;
    int cols;

    Location finish;

    enum cellTypes {Empty = ' ', Path = '#', Bad = 'b'};
    enum Directions { South = 0, East = 1, North = 2, West = 3};

public:
    Maze();
    ~Maze();

    //build maze
    void loadMaze(int choice);
    void fillArray(string fileName);

    //solve maze
    void solve();
    void canMove(Location loca, Directions direc);
    void Move(Directions direc, Stack *stack, Location *loca);

    //display maze
    void cleanUp();
    void drawMaze();


};


#endif //MAZESOLVER_MAZE_H
