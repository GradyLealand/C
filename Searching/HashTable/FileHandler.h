//
// Created by prog2100 on 10/04/18.
//

#ifndef HASHTABLE_FILEHANDLER_H
#define HASHTABLE_FILEHANDLER_H

#include <string>
#include "Hash.h"

using namespace std;

class FileHandler {
public:
    Hash sortDictionary(string readFile, Hash hash);
    void parseToCheck(string readFile, Hash hash);

};


#endif //HASHTABLE_FILEHANDLER_H
