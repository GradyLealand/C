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
    LinkedList readFileIn(string readFile, LinkedList list);
    void writeFileOut(string writeFile, LinkedList list);
    int inputCommand(string command, string fileOut, int selected, int size, LinkedList *list);
    void insertLine(int current, LinkedList *list);
    void deleteLine(int current, int size, string line1, string line2, LinkedList *list);
    void subsitiLine(int line, LinkedList *list);



};


#endif //LINEEDITOR_FILEHANDLER_H
