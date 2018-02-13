//
// Created by prog2100 on 11/02/18.
//

#include "Maze.h"
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

Maze::Maze() {}

Maze::~Maze() {}

void Maze::loadMaze(int choice)
{
    string fileName;

    //get the selected maze files name
    switch (choice)
    {
        case 1:
            fileName = "maze.txt";
            break;
        case 2:
            fileName = "maze2.txt";
            break;
        case 3:
            fileName = "maze3.txt";
            break;
        case 4:
            fileName = "maze4.txt";
            break;
        case 5:
            fileName = "mazex.txt";
            break;
        default:
            fileName = "maze.txt";
    }

    //get the maze dimensions
    ifstream fileIn;

    try
    {
        fileIn.open(fileName);
    }
    catch(const ifstream::failure& e)
    {
        cout << "Error reading the file" << endl;
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    string line;
    rows = 0;
    cols = 0;
    while(!fileIn.eof())
    {
        getline(fileIn, line);

        rows++;
        //only set the column size once
        if(cols == 0)
        {
            cols = (int)line.size();
        }

    }

    fileIn.close();

    //build array
    mazeArray = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        mazeArray[i] = new char[cols];
    }

    //set maze finish
    finish = Location(rows - 2, cols - 1);

    // fill the char[][]
    fillArray(fileName);

}//end load maze

void Maze::fillArray(string fileName)
{
    //fill array
    ifstream fileIn;
    fileIn.open(fileName);
    string addLine;
    while(!fileIn.eof())
    {
        for (int i = 0; i < rows; i++)
        {
            getline(fileIn, addLine);
            for (int j = 0; j < cols; j++)
            {
                mazeArray[i][j] = addLine[j];
                char x = addLine[j];
            }
        }
    }

    fileIn.close();
}//end fillArray

void Maze::drawMaze()
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mazeArray[i][j];
        }
        cout << endl;
    }
}//end drawMaze

void Maze::solve()
{
    //create the stack and set its top to the start location
    Stack stack;

    Location top;
    top.row = 1;
    top.col = 0;

    //while top's location is not the finish
    while(top.row != finish.row && top.col != finish.col)
    {
        move(&stack, &top);
        top = stack.get_top()->get_current();
    }


}//end solve

void Maze::move(Stack *stack, Location *location)
{
    Location current = *location;

    bool moveable = false;

    while(true)
    {
        //check for an empty space to the south
        if(canMove(current, South))
        {
            //set the curent location int he maze to #
            mazeArray[location->row][location->col] = '#';
            //move location to the new one
            current.row = current.row -1;
            //set moveable to true
            moveable = true;
            break;
        }
        //else check next

        //check for an empty space to the east
        if(canMove(current, East))
        {
            mazeArray[location->row][location->col] = '#';
            current.col = current.col + 1;
            moveable = true;
            break;
        }
        //else check next

        //check for an empty space to the west
        if(canMove(current, West))
        {
            mazeArray[location->row][location->col] = '#';
            current.col = current.col -1;
            moveable = true;
            break;
        }
        //else check next

        //check for an empty space to the north
        if(canMove(current, North))
        {
            mazeArray[location->row][location->col] = '#';
            current.row = current.row +1;
            moveable = true;
            break;
        }

        break;
    }

    if(moveable)
    {
        stack->push(current);
    }
    else
    {
        //set the current location to b
        mazeArray[location->row][location->col] = 'b';
        stack->pop();
    }



}//end move

bool Maze::canMove(Location location, Directions direction)
{
    switch(direction)
    {
        case South:
            return mazeArray[location.row - 1][location.col] == ' ';
        case East:
            return mazeArray[location.row][location.col + 1] == ' ';
        case West:
            return mazeArray[location.row][location.col - 1] == ' ';
        case North:
            return mazeArray[location.row + 1][location.col] == ' ';

    }

}//end canMove

//remove all b's from the maze before printing the result
void Maze::cleanUp()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if( mazeArray[i][j] == 'b')
            {
                mazeArray[i][j] = ' ';
            }
        }
    }
}
