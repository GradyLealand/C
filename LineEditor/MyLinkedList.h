//
// Created by prog2100 on 08/01/18.
//

#ifndef LINEEDITOR_MYLINKEDLIST_H
#define LINEEDITOR_MYLINKEDLIST_H
#include "Node.h"

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

    friend ostream& operator<<(ostream& output, LinkedList& list);
};


#endif //LINEEDITOR_MYLINKEDLIST_H
