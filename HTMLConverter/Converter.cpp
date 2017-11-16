//
// Created by prog2100 on 15/11/17.
//

#include "Converter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

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

void Converter::openFile()
{
    string line;
    ifstream fileIn;

    fileIn.open("/home/prog2100/CLionProjects/GitHub/HTMLConverter/convertMe.cpp");


    if(fileIn.is_open())
    {
        openWrite("<PRE>", true);
        cout << "File Open" << endl;
        while(!fileIn.eof())
        {
            getline(fileIn, line);
            openWrite(line, false);
        }
        openWrite("</PRE>", true);
    }
}

void Converter::openWrite(string line, bool tag)
{
    ofstream fileOut;
    //to append to a file - use ios::app
    fileOut.open("/home/prog2100/CLionProjects/GitHub/HTMLConverter/myFileOut.html",ios::app);

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
    else {
        cout << "Output file failed to open" << endl;
        cin.ignore();
    }
}