//
// Created by prog2100 on 08/01/18.
//

#include "FileHandler.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

void FileHandler::readFileIn(string readFile, LinkedList list)
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
            list.createNode(line);
    }

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

int FileHandler::inputCommand(string command,string fileOut, int selected, LinkedList list)
{
    regex regex1("\\b[a-zA-Z]\\s{1}\\d*\\s{1}\\d*");
    regex regex2("\\b[a-zA-Z]\\s{1}\\d*");
    regex regex3("\\b[a-zA-Z]");
    if(regex_match(command, regex3) || regex_match(command, regex2) || regex_match(command, regex1))
    {

        string action, arg1 = "", arg2 = "";
        int spaces = 0;

        //parse string into 3 possible commands
        for(int i = 0; i < command.length(); i++)
        {
            if(command[i] == ' ')
            {
                spaces++;
            }
            else
            {
                if(spaces == 0)
                {
                    action = command[i];
                }
                if(spaces == 1)
                {
                    arg1 += command[i];
                }
                if(spaces == 2)
                {
                    arg2 += command[i];
                }
            }
        }

        if(tolower(action[0]) == 'q')
        {
            cout << "Program closed after saving file";
            writeFileOut(fileOut, list);
            return 0;
        }
        else if(tolower(action[0]) == 'x')
        {
            cout << "Program closed without saving";
            return 0;
        }
        else if(tolower(action[0]) == 'i')
        {
            if(arg1 == "")
            {
                insertLine(selected, list);
            }
            else
            {
                insertLine(stoi(arg1), list);
            }
        }
        else if(tolower(action[0]) == 'd')
        {

        }
        else if(tolower(action[0]) == 'v')
        {

        }
        else if(tolower(action[0]) == 'g')
        {

        }
        else if(tolower(action[0]) == 's')
        {

        }
        else
        {
            cout << "Please enter a proper command" << endl;
        }

    }
    else
    {
        cout << "Please enter a proper command" << endl;
    }



    return selected;

}

int FileHandler::insertLine(int line, LinkedList list)
{
    string newLine;
    cout << "Insert in line" << line << ": ";
    getline(cin, newLine);

    //if line 1 insert at begining
    if(line == 1)
    {
        list.insertHead(newLine);
    }
    else
    {
        list.insterMid(line, newLine);
    }
}
