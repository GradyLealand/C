//
// Created by prog2100 on 30/03/18.
//

#ifndef AUTOBALANCING_FILEHANDLER_H
#define AUTOBALANCING_FILEHANDLER_H

#include <string>
#include "Tree.h"

using namespace std;

class FileHandler {
public:
    Tree sortDictionary(string readFile, Tree avlTree);
    void parseToCheck(string readFile, Tree avlTree);

};


#endif //AUTOBALANCING_FILEHANDLER_H
