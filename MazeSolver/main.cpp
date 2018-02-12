#include <iostream>
#include "Maze.h"

using namespace std;

Maze maze;

int main() {

    cout << "Select a maze: (1-5)" << endl;
    int choice;
    cin >> choice;
    maze.loadMaze(choice);
    cout << endl;
    cout << maze.mazeArray[2][2] << endl;
    cout << endl;

    maze.drawMaze();

    return 0;
}