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
    int inputCommand(string command, string fileOut, int selected, LinkedList *list);
    int insertLine(int line, LinkedList *list);
    int exitProgram();
    int saveAndExitProgram();



};


#endif //LINEEDITOR_FILEHANDLER_H
