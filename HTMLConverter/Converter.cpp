//
// Created by prog2100 on 15/11/17.
//

#include "Converter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <regex>

class IOException;

class Exception;

using namespace std;

bool Converter::fileExists(const string &fileName)
{
    struct stat buf;
    if (stat(fileName.c_str(), &buf) != -1)
    {
        cout << "the file exists" << endl;
        return true;
    }
    return false;

}

void Converter::openFile(string fileRead, string fileWrite)
{
    string line;
    ifstream fileIn;

    fileIn.open(fileRead);


    if(fileIn.is_open())
    {
        openWrite(fileWrite, "<PRE>", true);
        cout << "File Open" << endl;
        while(!fileIn.eof())
        {
            getline(fileIn, line);
            openWrite(fileWrite, line, false);
        }
        openWrite(fileWrite, "</PRE>", true);
    }
    if(fileIn.fail())
    {
        cout << "failed to open file";
    }
}

void Converter::openWrite(string file, string line, bool tag)
{
    ofstream fileOut;
    //to append to a file - use ios::app
    fileOut.open(file,ios::app);

    if (fileOut.is_open())//or if(myFileOut.fail)
    {
        if(!tag)
        {
            int count = 0;
            while(count < line.length())
            {
                string c;
                if(line[count] == '<') {
                    fileOut << "&lt";
                }
                else if(line[count] == '>')
                {
                    fileOut << "&gt";
                }
                else
                {
                    fileOut << line[count];
                }

                count++;
            }
            fileOut << endl;
        }
        else
        {
            fileOut << line;
            fileOut << endl;
        }

    }
    else if(fileOut.fail())
    {
        cout << "Output file failed to open" << endl;
        cin.ignore();
    }
}

string Converter::requestOpenFile()
{
    string file;
    regex exp("^\\/(...)*.\\.cpp$");
    bool exists;

    do{
        //ask for a file name
        cout << "enter a name of a file to be converted:";
        cin >> file;
        //check to see if its a valid file name
        exists = fileExists(file);
        if(!(regex_match(file, exp)))
        {
            cout << "pleases enter a proper cpp file name." << endl;
        }
        else if (!exists)
        {
            cout<< "That file dose not exist" << endl;
        }

    }while (!(regex_match(file, exp)) || !exists);

    return file;
}

//----Getters & Setters----
const string &Converter::getReadFile() const {
    return readFile;
}

void Converter::setReadFile(const string &readFile) {
    Converter::readFile = readFile;
}

const string &Converter::getWriteFile() const {
    return writeFile;
}

void Converter::setWriteFile(const string &writeFile) {
    Converter::writeFile = writeFile;
}
