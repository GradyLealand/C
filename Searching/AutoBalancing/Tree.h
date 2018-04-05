//
// Created by prog2100 on 30/03/18.
//

#ifndef AUTOBALANCING_TREE_H
#define AUTOBALANCING_TREE_H

#include <string>

using namespace std;

struct Node
{
    string data;

    struct Node *left;
    struct Node *right;
};

class Tree {

public:
    Node *root;

    int height(Node *);
    int diff(Node *);

    Node *rr_rotate(Node *);
    Node *ll_rotate(Node *);
    Node *lr_rotate(Node *);
    Node *rl_rotate(Node *);
    Node* balance(Node *);
    Node* insert(Node *, string);

    void displayTree(Node *, int);

    Tree();

    void placeNode(string line);

    void spellCheck(string word, Tree dictionary);
};


#endif //AUTOBALANCING_TREE_H
