//
// Created by prog2100 on 19/01/18.
//

#include "LinkedList.h"
#include <string>
#include <utility>
#include <iostream>

using namespace std;



LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

//create a new node and add it to the list
void LinkedList::createNode(string line)
{
    node *temp = new node;
    temp->data = line;
    temp->next = nullptr;

    //if the link list is empty
    if(head == NULL)
    {
        //set temp as the head and tail of the list
        head = temp;
        tail = temp;
        //reset *temp
        temp = nullptr;
    }
    else
    {
        //set the current tail to point to the new tail (temp)
        tail->next = temp;
        //set temp as the new tail
        tail = temp;
    }
}//end createNode();

//display all nodes in the list
void LinkedList::display()
{
    //make a pointer to walk through the list
    node *temp = new node;
    //set the pointer equal to the head node
    temp = head;

    //a variable to hold the line count
    int count = 1;
    while(temp != nullptr)
    {
        //ass long as the pointer is not null print the node it is on
        cout << count << ". " << temp->data << endl;
        //then move the pointer to the next node
        temp=temp->next;
        count++;
    }
}

//display all nodes in the list
void LinkedList::displaySelected(int start, int finish) {
    //make a pointer to walk through the list
    node *temp = new node;
    //set the pointer equal to the head node
    temp = head;

    for(int i = 1; i <= finish; i++) {
        //only print the lines once they reach the selected area
        if(i >= start)
        {
            //ass long as the pointer is not null print the node it is on
            cout  << i << ". " << temp->data << endl;
        }
        //move the pointer to the next node
        temp = temp->next;

    }
}

//insert a line at the beginning of the list
void LinkedList::insertHead(string line)
{
    node *temp = new node;
    temp->next = head;
    temp->data = line;
    head = temp;
}

//insert a line at a specific point in th list
void LinkedList::insterMid(int position, string line)
{
    node *temp = new node;
    node *prev = new node;
    node *crnt = new node;
    crnt = head;

    //find the node currently in the posision
    for(int i = 1; i < position; i++)
    {
        prev = crnt;
        crnt = crnt->next;
    }

    prev->next = temp;
    temp->next = crnt;
    temp->data = line;
}

//delete the first node from the list
void LinkedList::deleteHead()
{
    node *temp = new node;
    //set temp to the current head
    temp = head;
    //set the node after head to the current head
    head = head->next;
    //delete the old head that temp is pointing too
    delete temp;
}

//delete the last node in the list
void LinkedList::deleteTail()
{
    node *crnt = new node;
    node *prev = new node;
    crnt = head;

    while(crnt->next != nullptr)
    {
        prev = crnt;
        crnt = crnt->next;
    }

    tail = prev;
    tail->next = nullptr;
    delete crnt;
}

//delete the node at a specific position in the list
void LinkedList::deleteMid(int position)
{
    node *prev = new node;
    node *crnt = new node;
    crnt = head;

    for(int i = 1; i < position; i++)
    {
        prev = crnt;
        crnt = crnt->next;
    }
    prev->next = crnt->next;
}

node *LinkedList::getHead() const {
    return head;
}

node *LinkedList::getTail() const {
    return tail;
}

//returns how made nodes are in the list
int LinkedList::countLines()
{
    //make a pointer to walk through the list
    node *temp = new node;
    //set the pointer equal to the head node
    temp = head;

    //a variable to hold the line count
    int count = 0;
    while(temp != nullptr)
    {
        temp=temp->next;
        count++;
    }

    return count;
}















































