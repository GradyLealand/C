//
// Created by prog2100 on 30/03/18.
//

#include "Tree.h"
#include <iostream>

using namespace std;
Tree::Tree()
{
    root = nullptr;
}


/*
 * code developed by following example:
 * https://www.sanfoundry.com/cpp-program-implement-avl-trees/
 */

//the current height of the tree
int Tree::height(Node *temp)
{
    int currentHeight = 0;

    if (temp != NULL)
    {

        int left_height = height (temp->left);
        int right_height = height (temp->right);
        int max_height = max (left_height, right_height);
        currentHeight = max_height + 1;
    }

    return currentHeight;
}

//get the differance in height to balance
int Tree::diff(Node *temp)
{
    int left_height = height(temp->left);
    int right_height = height(temp->right);

    int balance = left_height - right_height;
    return balance;
}

//right right rotation
Node* Tree::rr_rotate(Node *previous)
{
    Node *temp;
    temp = previous->right;
    previous->right = temp->left;
    temp->left = previous;
    return temp;
}

//left left rotation
Node* Tree::ll_rotate(Node *previous)
{
    Node *temp;
    temp = previous->left;
    previous->left = temp->right;
    temp->right = previous;
    return temp;
}

//left right rotation
Node* Tree::lr_rotate(Node *previous)
{
    Node *temp;
    temp = previous->left;
    previous->left = rr_rotate(temp);
    return ll_rotate(previous);
}

//right left rotation
Node* Tree::rl_rotate(Node *previous)
{
    Node *temp;
    temp = previous->right;
    previous->right = ll_rotate(temp);
    return rr_rotate(previous);
}

//balance the tree
Node* Tree::balance(Node *temp)
{
    int balance = diff(temp);
    if (balance > 1)
    {
        if (diff(temp->left) > 0)
        {
            temp = ll_rotate(temp);
        }
        else
        {
            temp = lr_rotate(temp);
        }
    }
    else if (balance < -1)
    {
        if(diff(temp->right) > 0)
        {
            temp = rl_rotate(temp);
        }
        else
        {
            temp = rr_rotate(temp);
        }
    }

    return temp;
}

//insert into the tree
Node* Tree::insert(Node *root, string word)
{
    if(root == nullptr)
    {
        root = new Node;
        root->data = word;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    else if(word < root->data)
    {
        root->left = insert(root->left, word);
        root = balance(root);
    }
    else if(word > root->data)
    {
        root->right = insert(root->right, word);
        root = balance(root);
    }

    return root;
}

void Tree::spellCheck(string word, Tree dictionary)
{
    Node *temp = root;
    while(true)
    {
        //check for a match
        if(temp->data == word)
        {
            //do nothing. The word is spelt correctly
            break;
        }

        //compare and move down the tree
        if(word < temp->data)
        {
            //if nullptr then the word was not in the dictionary and must be spelt wrong
            if(temp->left == nullptr)
            {
                cout << word << endl;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
            //check right side
        else
        {
            if(temp->right == nullptr)
            {
                cout << word << endl;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }

}

//display the sorted tree
void Tree::displayTree(Node *ptr, int level)
{
    int i;
    if (ptr!= nullptr)
    {
        displayTree(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        displayTree(ptr->left, level + 1);
    }
}


