#include <iostream>
#include "LinkedList.h"
#include "FileHandler.h"

using namespace std;

int main() {
    FileHandler fileHandler;
    bool quitEditor = false;
    int curentLine = 1, listSize;


    //ask for file name
        //check to see if file exists
            //if it dose oppen file
            //if not tell user and ask again

    //display file content
        //look for user input
            //check for command, edit, exit or save


    // test 1: adding new nodes
    LinkedList obj;
    obj = fileHandler.readFileIn("/home/prog2100/CLionProjects/GitHub/LineEditor/in.txt", obj);
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
    //fileHandler.readFileIn("/home/prog2100/CLionProjects/GitHub/LineEditor/text.txt", obj);
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"---------------Displaying All nodes---------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"-----------------Inserting At End-----------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.createNode("meow");
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"----------------Deleting At Start-----------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.deleteHead();
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"----------------Inserting At Start----------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.insertHead("this");
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"-------------Inserting At Particular--------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.insterMid(5, "LinkedList");
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"-----------------Deleting At End-------------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.deleteTail();
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";
//    cout<<"--------------Deleting At Particular--------------";
//    cout<<"\n--------------------------------------------------\n";
//    obj.deleteMid(3);
//    obj.display();
//    cout<<"\n--------------------------------------------------\n";



    return 0;
}