#include <iostream>
#include <fstream>
#include "FileHandler.h"

using namespace std;
int main() {
    FileHandler fileHandler;

    fileHandler.splitFile("file1.txt", "file2.txt", "phonebook.txt");

    return 0;
}

/*
 * 7 1 5 3 14 12 8 6 4
 * split into  two files
 * f1) 7 5 14 8 4
 * f2) 1 3 12 6
 *
 * compare each index[n] and sort
 *
 * f3)1 7 12 14 4
 * f4)3 5 6 8
 *
 * double the run size
 *
 * f4)1 3 5 7 4
 * f5)6 8 12 14
 *
 * double run size
 * f6)1 3 5 6 7 8 12 14
 * f7)4
 *
 *
 */