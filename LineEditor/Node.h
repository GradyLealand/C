//
// Created by prog2100 on 08/01/18.
//

#ifndef LINEEDITOR_NODE_H
#define LINEEDITOR_NODE_H


class Node
{
public:
    int data;
    Node *next;

    Node() : next(nullptr), data(-1) {}
};


#endif //LINEEDITOR_NODE_H
