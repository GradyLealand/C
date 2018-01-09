#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main() {
    //ask for file name
        //check to see if file exists
            //if it dose oppen file
            //if not tell user and ask again

    //display file content
        //look for user input
            //check for command, edit, exit or save


    // test 1: adding new nodes

    MyLinkedList list;

    list.Add(3);
    list.Add(5);
    list.Add(1);
    list.Add(7);
    list.Add(9);
    list.Add(13);
    list.Add(20);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;

    // test 2: delete a node

    cout << "\nDeleting...." << endl;

    list.DeleteValue(1);
    list.DeleteNode(2);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;

    // test 3: insert a node

    cout << "\nInserting...." << endl;

    // tests to insert after valid node
    list.InsertAfterValue(3, 10);
    // test to insert after non-existent node
    list.InsertAfterValue(25, 33);
    list.InsertBeforeNode(5,11);

    cout << "The list contains the following numbers: " << endl << endl;
    cout << list;
    cin.ignore();
    return 0;
}