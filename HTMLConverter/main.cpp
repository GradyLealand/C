#include <iostream>
#include "Converter.h"

class Converter;

int main() {
    bool exists = false;
    //instance converter
    Converter con;

    con.setReadFile(con.requestOpenFile());

    con.setWriteFile(con.requestWriteFile());

    con.openFile(con.getReadFile(), con.getWriteFile());

    return 0;
}