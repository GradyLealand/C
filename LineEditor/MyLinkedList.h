//
// Created by prog2100 on 08/01/18.
//

#ifndef LINEEDITOR_MYLINKEDLIST_H
#define LINEEDITOR_MYLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class MyLinkedList {
private:
    Node *first;

public:
    MyLinkedList();

    virtual ~MyLinkedList();

    void Add(int num);

    void DeleteValue(int value);

    void DeleteNode(int nodenum);

    void InsertAfterValue(int value, int num);

    void InsertBeforeNode(int nodenum, int num);

    friend ostream &operator<<(ostream &output, MyLinkedList &list);
};


#endif //LINEEDITOR_MYLINKEDLIST_H
