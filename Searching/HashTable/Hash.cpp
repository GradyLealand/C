//
// Created by prog2100 on 10/04/18.
//

#include "Hash.h"
#include <string>
#include <iostream>

using namespace std;

Hash::Hash()
{
    for(int i = 0; i < SIZE; i++)
    {
        HashTable[i] =  new entry;
        HashTable[i]->word = "";
        HashTable[i]->next = nullptr;
    }
}

int Hash::doHash(string key)
{
    int hash = 0;
    int index;
    for(int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i];
    }

    index = hash % SIZE;

    return index;

}

void Hash::addEntry(string word)
{
    int index = doHash(word);

    if(HashTable[index]->word == "")
    {
        HashTable[index]->word = word;
    }
    else
    {
        entry* temp = HashTable[index];
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        entry* n = new entry;
        n->word = word;
        n->next = nullptr;

        temp->next = n;

    }
}

void Hash::printTable()
{
    cout << "Hash table:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << i << ": ";

        entry* temp = HashTable[i];
        if(temp->word != "")
        {
            cout << temp->word;
            while(temp->next != nullptr)
            {
                cout <<", ";
                temp = temp->next;
                cout << temp->word;
            }
        }

        cout << endl;
    }
}

void Hash::spellCheck(string word, Hash hash)
{
    int index = doHash(word);

    if(hash.HashTable[index]->word != "")
    {
        entry* temp = hash.HashTable[index];

        if(temp->word == word)
        {
            return;
        }
        while(temp->next != nullptr)
        {
            temp = temp->next;
            if(temp->word == word)
            {
                return;
            }
        }
        cout << word << " ";
    }
    else
    {
        cout << word << " ";
    }
}