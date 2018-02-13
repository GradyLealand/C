//
// Created by prog2100 on 12/02/18.
//

#include "StackNode.h"

//default constructor
StackNode::StackNode(Location current, StackNode *next) : _current(current), _next(next){}

//default destructor
StackNode::~StackNode() {}

//getters and setters
const Location &StackNode::get_current() const {
    return _current;
}

void StackNode::set_current(const Location &_current) {
    StackNode::_current = _current;
}

StackNode *StackNode::get_next() const {
    return _next;
}

void StackNode::set_next(StackNode *_next) {
    StackNode::_next = _next;
}
