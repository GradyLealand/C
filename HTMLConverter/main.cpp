#include <iostream>
#include "Converter.h"

class Converter;

int main() {
    bool exists = false;
    //instance converter
    Converter con;

    exists = con.fileExists("/home/prog2100/CLionProjects/GitHub/HTMLConverter/myFileIn.txt");

    cout << exists << endl;

    con.openFile();


    return 0;
}