#include <iostream>
#include "LinkedList.h"
#include "FileHandler.h"

using namespace std;

int main(int argc, char *argv[]) {
    FileHandler fileHandler;
    bool quitEditor = false;
    int curentLine = 1, listSize;

    LinkedList obj;
    obj = fileHandler.readFileIn("/home/prog2100/CLionProjects/GitHub/LineEditor/in.txt", obj);
    cout << endl;
    obj.display();
    listSize = obj.countLines();

    while(curentLine != 0)
    {
        string command;
        cout << "\nLine" << curentLine << ">>";
        getline(cin, command);
        curentLine = fileHandler.inputCommand(command, "/home/prog2100/CLionProjects/GitHub/LineEditor/out.txt", curentLine, listSize, &obj);
        listSize = obj.countLines();
    }

    return 0;
}