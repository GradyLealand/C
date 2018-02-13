//
// Created by prog2100 on 12/02/18.
//

#ifndef MAZESOLVER_STACK_H
#define MAZESOLVER_STACK_H


#include "StackNode.h"


class Stack {
private:
    StackNode *_top;

public:
    //default constructor and deconstructor
    Stack();
    virtual ~Stack();

    void push(Location current);
    Location peek();
    void pop();
    bool empty();

    //getters and setters
    StackNode *get_top() const;

    void set_top(StackNode *_top);
};


#endif //MAZESOLVER_STACK_H
