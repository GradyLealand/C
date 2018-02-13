//
// Created by prog2100 on 12/02/18.
//

#include "Stack.h"
#include <iostream>

using namespace std;

//Default constructor
Stack::Stack() : _top(nullptr) {}

//default destructor
Stack::~Stack()
{
    while(_top != nullptr)
    {
        pop();
    }
}

//push a new stacknode to the top of the stack
void Stack::push(Location current)
{
    _top = new StackNode(current, _top);
}

//get the location of the top stackNode
Location Stack::peek()
{
    return  _top->get_current();
}

//remove the top and set the previous node to the new top
void Stack::pop()
{
    //if not null
    if(_top != nullptr)
    {
        //move the current node to a temp points
        StackNode* node = _top;
        //set the top pointer to the current tops next
        _top = _top->get_next();
        //delete old top
        delete(node);
    }
    else //return some error
    {
        cerr << "error: Stack is empty. Can not perform pop()." <<endl;
    }
}

//check to see if the stack is empty
bool Stack::empty()
{
    return _top != nullptr;
}

StackNode *Stack::get_top() const {
    return _top;
}

void Stack::set_top(StackNode *_top) {
    Stack::_top = _top;
}

