#include <iostream>
#include "Hash.h"
#include "FileHandler.h"

int main() {
    string pathRoot = "/home/prog2100/CLionProjects/GitHub/Searching/HashTable/";
    FileHandler fileHandler;
    Hash dictionary;


    dictionary = fileHandler.sortDictionary(pathRoot + "dictionary.txt", dictionary);
    dictionary.printTable();
    fileHandler.parseToCheck(pathRoot + "mispelled.txt", dictionary);

    return 0;
}