//
// Created by prog2100 on 10/04/18.
//

#ifndef HASHTABLE_HASH_H
#define HASHTABLE_HASH_H

#include <string>

using namespace std;

class Hash {
private:
    static const int SIZE = 53;
    static const int SEED = 101;

    struct entry{
        string word;
        entry* next;
    };

    entry* HashTable[SIZE];

    int collisions = 0;

public:
    Hash();

    int doHash(string key);

    void addEntry(string word);
    void printTable();

    void spellCheck(string word, Hash hash);
};


#endif //HASHTABLE_HASH_H
