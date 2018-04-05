#include <iostream>
#include "FileHandler.h"

int main() {
    string pathRoot = "/home/prog2100/CLionProjects/GitHub/Searching/AutoBalancing/";
    FileHandler fileHandler;
    Tree dictionary;


    dictionary = fileHandler.sortDictionary(pathRoot + "dictionary.txt", dictionary);
    dictionary.displayTree(dictionary.root, 1);
    fileHandler.parseToCheck(pathRoot + "mispelled.txt", dictionary);

    return 0;
}