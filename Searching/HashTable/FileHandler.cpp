//
// Created by prog2100 on 10/04/18.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "FileHandler.h"
#include <locale>

using namespace std;

Hash FileHandler::sortDictionary(string readFile, Hash hash)
{
    string line;
    ifstream fileIn;
    try{
        fileIn.open(readFile);
    }
    catch(const ifstream::failure& e)
    {
        cout << "Error reading the file" << endl;
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    while (!fileIn.eof())
    {
        getline(fileIn, line);
        hash.addEntry(line);
    }

    fileIn.close();

    return hash;
}

/*
 * split into individual words and exclude special characters
 * http://www.cplusplus.com/reference/cstring/strtok/
 */
void FileHandler::parseToCheck(string readFile, Hash hash)
{
    cout << endl;
    cout << "Misspelled words:" << endl;
    locale loc;
    ifstream fileIn(readFile);
    string content((istreambuf_iterator<char>(fileIn)),
                   (istreambuf_iterator<char>()));

    char str[content.length()];
    for(int i = 0; i < content.length(); i++)
    {
        str[i] = content[i];
    }

    char * pch;
    pch = strtok (str, " .,()#&\"1234567890");
    while (pch != NULL)
    {
        string checkStr = "";
        checkStr += ("%s\n", pch);
        pch = strtok (NULL, " .,()#&\"1234567890");
        //convert string to lower case
        for(int i = 0; i <checkStr.length(); i++)
        {
            checkStr[i] = tolower(checkStr[i], loc);
        }
        hash.spellCheck(checkStr, hash);
    }
}
