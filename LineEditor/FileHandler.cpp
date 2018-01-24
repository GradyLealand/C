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

LinkedList FileHandler::readFileIn(string readFile, LinkedList list)
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

    return list;
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

int FileHandler::inputCommand(string command,string fileOut, int current, int size, LinkedList *list)
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

        if(tolower(action[0]) == 'e')
        {
            cout << "Program closed after saving file";
            writeFileOut(fileOut, *list);
            return 0;
        }
        else if(tolower(action[0]) == 'q')
        {
            cout << "Program closed without saving";
            return 0;
        }
        else if(tolower(action[0]) == 'i')
        {
            if(!arg2.empty())
            {
                cout << "The command i (insert) may only have 1 or no arguments. ex: i 3 or i" << endl;
            }
            else if(arg1.empty())
            {
                insertLine(current, list);
            }
            else
            {
                insertLine(stoi(arg1), list);
            }
        }
        else if(tolower(action[0]) == 'd')
        {
            bool passed = true;
            //check to make sure the lines to delete exist
            if(!arg2.empty())
            {
                if(stoi(arg2) > size)
                {
                    cout << "Can not delete lines that do not exist" << endl;
                    passed = false;
                }
                if(!arg1.empty())
                {
                    if(stoi(arg1) >= stoi(arg2))
                    {
                        cout << "First argument must be smaller then second" << endl;
                        passed = false;
                    }
                }
            }
            if(!arg1.empty())
            {
                if(stoi(arg1) > size)
                {
                    cout << "Can not delete lines that do not exist" << endl;
                    passed = false;
                }
            }

            if(passed)
            {
                deleteLine(current, size, arg1, arg2, list);
            }

        }
        else if(tolower(action[0]) == 'v')
        {
            //make sure no arguments are entered
            if(!arg1.empty())
            {
                cout << "The command v (view) may not take any arguments" << endl;
            }
            else
            {
                LinkedList temp = *list;
                cout << endl;
                temp.display();
            }
        }
        else if(tolower(action[0]) == 'g')
        {
            //make sure that one and only one argument is entered
            if(arg1.empty() || !arg2.empty())
            {
                cout << "The command g (go to line) must take in only one argument. ex: g 2" << endl;
            }
            else
            {
                // if arg one is greater then the num of lines set the first line as selected
                if(stoi(arg1) > size)
                {
                    current = 1;
                }
                else
                {
                    current = stoi(arg1);
                }
            }
        }
        else if(tolower(action[0]) == 's')
        {
            if(!arg2.empty())
            {
                cout << "The command s (substitute) can only take one or no arguments. ex: s or s 3" << endl;
            }
            else if(!arg1.empty())
            {
                //delete selected line
                deleteLine(current, size, arg1, arg2, list);
                //insert where deleted line was
                insertLine(stoi(arg1), list);
            }
            else
            {
                deleteLine(current, size, arg1, arg2, list);
                insertLine(current, list);
            }

        }
        else if(tolower(action[0]) == 'l')
        {
            bool passed = true;
            //check to make sure the lines to delete exist
            if(arg2.empty())
            {
                cout << "The command l (list) must have two arguments with the second larger then the first. ex: l 3 5" << endl;
            }
            if(!arg2.empty())
            {
                if(stoi(arg2) > size)
                {
                    cout << "Line " << arg2 << "dose not exist" << endl;
                    passed = false;
                }
                if(!arg1.empty())
                {
                    if(stoi(arg1) >= stoi(arg2))
                    {
                        cout << "The command l (list) must have two arguments with the second larger then the first. ex: l 3 5" << endl;
                        passed = false;
                    }
                }
            }

            if(passed)
            {
                LinkedList temp = *list;
                temp.displaySelected(stoi(arg1), stoi(arg2));
            }
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
    return current;
}

//inset a node in the linked list at the specified posision
void FileHandler::insertLine(int current, LinkedList *list)
{
    LinkedList temp = *list;
    string newLine;
    cout << "Insert in line" << current << ": ";
    getline(cin, newLine);

    //if line 1 insert at beginning
    if(current == 1)
    {
        temp.insertHead(newLine);
        *list = temp;
    }
    else
    {
        temp.insterMid(current, newLine);
        *list = temp;
    }
}

//delete the node(s) at a specified position
void FileHandler::deleteLine(int current, int size, string line1, string line2, LinkedList *list)
{
    LinkedList temp = *list;

    //if line2 is empty then we will delete a specific node
    if(line2.empty())
    {
        int toDelete;
        if(line1.empty())
        {
            toDelete = current;
        } else
        {
            toDelete = stoi(line1);
        }

        //check to see if the index is
        if(toDelete == 1)
        {
            temp.deleteHead();
        }
        else if(toDelete == size)
        {
            temp.deleteTail();
        }
        else
        {
            temp.deleteMid(toDelete);
        }

    }
    else
    {
        int n = stoi(line1);
        int m = stoi(line2);
        if(m == size)
        {
            for(int i = m; i >= n; i--)
            {
                temp.deleteTail();
            }
        }
        else
        {
            for(int i = m; i >= n; i--)
            {
                temp.deleteMid(i);
            }
        }


    }

    *list = temp;
}





