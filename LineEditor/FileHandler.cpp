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
    ofstream fileOut;

    //to append to a file - use ios::app
    try
    {
        fileOut.open(writeFile,ios::app);
        fileOut.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
    }
    catch(const ofstream::failure& e)
    {
        cout << "Error opening write file";
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }


    if (fileOut.is_open())//or if(myFileOut.fail)
    {
        //make a pointer to walk through the list
        node *temp = new node;
        //set the pointer equal to the head node
        temp = list.getHead();

        while(temp != nullptr)
        {
            string line = temp->data;
            fileOut << line << endl;
            temp=temp->next;
        }
    }
    else if(fileOut.fail())
    {
        cout << "Output file failed to open" << endl;
        cin.ignore();
    }

    try{
        fileOut.close();
    }
    catch(exception& e)
    {
        cout << "error while closing write file";
    }
}