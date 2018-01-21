//
// Created by prog2100 on 19/01/18.
//

#ifndef LINEEDITOR_LINKEDLIST_H
#define LINEEDITOR_LINKEDLIST_H
#include <string>
#include "node.h"

using namespace std;
class LinkedList {


private:
    node *head, *tail;



public:

    LinkedList();

    void createNode(string line);
    void display();
    void insertHead(string line);
    void insterMid(int position, string line);
    void deleteHead();
    void deleteTail();
    void deleteMid(int position);

    node *getHead() const;

    node *getTail() const;


};


#endif //LINEEDITOR_LINKEDLIST_H
