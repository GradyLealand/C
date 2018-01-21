//
// Created by prog2100 on 08/01/18.
//

#ifndef LINEEDITOR_FILEHANDLER_H
#define LINEEDITOR_FILEHANDLER_H

#include <string>
#include "LinkedList.h"

using namespace std;

class FileHandler {
private:

public:
    void readFileIn(string readFile, LinkedList list);
    void writeFileOut(string writeFile, LinkedList list);


};


#endif //LINEEDITOR_FILEHANDLER_H
