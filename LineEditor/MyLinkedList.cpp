//
// Created by prog2100 on 08/01/18.
//

#include "MyLinkedList.h"
MyLinkedList::MyLinkedList() : first(nullptr) {}

virtual MyLinkedList:: ~MyLinkedList()
{
    Node *node = first;

    while (node != nullptr)
    {
        Node *temp = node;

        node = node->next;

        delete temp;
    }
}

void MyLinkedList::Add(int num)
{
    Node *node = new Node();
    node->data = num;

    if (first == nullptr)
    {
        first = node;
    }
    else
    {
        Node *currNode = first;
        Node *prevNode = nullptr;

        while (currNode != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (prevNode != nullptr)
        {
            prevNode->next = node;
        }
    }
}

void MyLinkedList::DeleteValue(int value)
{
    Node *node = first;
    Node *prev = nullptr;

    while (node != nullptr)
    {
        if (node->data == value)
        {
            break;
        }

        prev = node;
        node = node->next;
    }

    if (node != nullptr)
    {
        if (node == first)
        {
            first = node->next;
        }
        else
        {
            prev->next = node->next;
        }

        delete node;
    }
}

void MyLinkedList::DeleteNode(int nodenum)
{
    int index = -1;

    Node *node = first;
    Node *prev = nullptr;

    while (node != nullptr)
    {
        index++;

        if (index == nodenum)
        {
            break;
        }

        prev = node;
        node = node->next;
    }

    if (index >= 0)
    {
        if (node == first)
        {
            first = node->next;
        }
        else
        {
            prev->next = node->next;
        }

        delete node;
    }
}

void MyLinkedList::InsertAfterValue(int value, int num)
{
    Node *node = new Node();
    node->data = num;

    // search for node to insert after
    Node *prev = first;

    while (prev != nullptr)
    {
        if (prev->data == value)
        {
            break;
        }

        prev = prev->next;
    }

    // insert node into list
    if (first == nullptr)
    {
        first = node;
    }
    else
    {
        if (prev != nullptr)
        {
            node->next = prev->next;
            prev->next = node;
        }
        else
        {
            // could not find the node to insert after
            // so defaulting to Add function
            Add(num);
        }
    }
}

MyLinkedList::ostream& operator<<(ostream& output, LinkedList& list)
{
    Node *currNode = list.first;

    while (currNode != nullptr)
    {
        output << "data = " << currNode->data << endl;

        currNode = currNode->next;
    }

    return output;
}
};

