//
// Created by prog2100 on 11/02/18.
//

#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H

#include <string>

using namespace std;


class Maze {

public:
    char** mazeArray;
    int rows;
    int cols;

    Maze();
    ~Maze();

    void loadMaze(int choice);
    void drawMaze();
    void fillArray(string fileName);


};


#endif //MAZESOLVER_MAZE_H
