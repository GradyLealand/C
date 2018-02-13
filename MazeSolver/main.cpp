#include <iostream>
#include "Maze.h"

using namespace std;

Maze maze;

int main() {

    cout << "Select a maze: (1-5)" << endl;
    int choice;
    cin >> choice;
    maze.loadMaze(choice);

    maze.solve();

    maze.cleanUp();

    maze.drawMaze();

    return 0;
}