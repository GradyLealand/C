//
// Created by prog2100 on 08/01/18.
//

#include "FileHandler.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void FileHandler::readFileIn(string readFile, LinkedList list)
{
    string line;
    ifstream fileIn;
    try{
        fileIn.open(readFile);
        fileIn.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
    }
    catch(const ifstream::failure& e)
    {
        cout << "Error reading the file" << endl;
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //read each line int he file
    do
    {
        try{

            getline(fileIn, line);
            list.createNode(line);
            cin.ignore();
            fileIn.exceptions(ifstream::eofbit);
        }catch(ifstream::failure e){
            std::cerr << "Exception happened: " << e.what() << "\n"
                      << "Error bits are: "
                      << "\nfailbit: " << fileIn.fail()
                      << "\neofbit: " << fileIn.eof()
                      << "\nbadbit: " << fileIn.bad() << std::endl;
        }

    }
    while (!fileIn.eof());

    fileIn.close();
}

void FileHandler::writeFileOut(string writeFile, LinkedList list)
{

}