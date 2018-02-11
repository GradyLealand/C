//
// Created by prog2100 on 11/02/18.
//

#include "Maze.h"
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

Maze::Maze()
{

}

Maze::~Maze()
{

}

void Maze::loadMaze(int choice)
{
    string fileName;


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
        cols = (int)line.size();
    }

    fileIn.close();

    //build array
    mazeArray = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        mazeArray[i] = new char[cols];
    }

    fillArray(fileName);

}//end load maze


void Maze::fillArray(string fileName)
{
    //fill array
    ifstream arrayFile;
    arrayFile.open(fileName);
    string addLine;
    while(!arrayFile.eof())
    {
        for (int i = 0; i < rows; i++)
        {
            getline(arrayFile, addLine);
            for (int j = 0; j < cols; j++)
            {
                mazeArray[i][j] = addLine[j];
                char x = addLine[j];
            }
        }
    }
}
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
}





























