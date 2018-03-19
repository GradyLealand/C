//
// Created by prog2100 on 19/03/18.
//

#include <fstream>
#include <iostream>
#include "FileHandler.h"

using namespace std;


FileHandler::FileHandler()
{
    basePath = "/home/prog2100/CLionProjects/GitHub/Sorting/Part2/";
    _if1 = new fstream;
    _if2 = new fstream;
    _if3 = new fstream;
    _if4 = new fstream;
    _of1 = new fstream;
    _of2 = new fstream;
    _of3 = new fstream;
    _of4 = new fstream;


}

void FileHandler::splitFile(string fileOne, string fileTwo, string dataFile)
{
    //string to hold line
    string line;

    //bool to say which file to save too
    bool saveFO1 = true;



    try{
         _if1->open(basePath + dataFile);
    }
    catch(const ifstream::failure& e)
    {
        cout << "Error reading the file" << endl;
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }


    //open the files to write too
    try
    {
        _of1->open(basePath + fileOne, ofstream::out | ofstream::trunc);
        _of1->exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
        _of2->open(basePath + fileTwo, ofstream::out | ofstream::trunc);
        _of2->exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
    }
    catch(const ofstream::failure& e)
    {
        cout << "Error opening write file";
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //write lines to alternate files
    if (_of1->is_open() && _of2->is_open())//or if(myFileOut.fail)
    {
        while (!_if1->eof())
        {
            if(saveFO1)
            {
                getline(*_if1, line);
                *_of1 << line << endl;
                saveFO1 = false;
            }
            else
            {
                getline(*_if1, line);
                *_of2 << line << endl;
                saveFO1 = true;
            }
        }
    }

    //close of and ifstreams
    try{
        _of1->close();
        _of2->close();
        _if1->close();
    }
    catch(exception& e)
    {
        cout << "error while closing write file";
    }
}