#include <iostream>
#include "Converter.h"

class Converter;

int main() {
    bool exists = false;
    //instance converter
    Converter con;

    con.setReadFile(con.requestOpenFile());

    con.openFile(con.getReadFile(), "/home/prog2100/CLionProjects/GitHub/HTMLConverter/myFileOut.html");


    return 0;
}