//
// Created by prog2100 on 12/02/18.
//

#ifndef MAZESOLVER_STACKNODE_H
#define MAZESOLVER_STACKNODE_H

struct Location
{
    //the default start location
    int row {1};
    int col {0};

    //build the default location
    Location() = default;
    Location(int row, int col) : row(row), col(col) {}
    bool equals(Location l);

};

class StackNode {
private:
    Location _current;
    StackNode *_next;
public:
    StackNode(Location current, StackNode* next);
    virtual ~StackNode();

    //getters and setters
    const Location &get_current() const;

    void set_current(const Location &_current);

    StackNode *get_next() const;

    void set_next(StackNode *_next);

};


#endif //MAZESOLVER_STACKNODE_H
