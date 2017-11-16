//
// Created by prog2100 on 15/11/17.
//

#ifndef HTMLCONVERTER_CONVERTER_H
#define HTMLCONVERTER_CONVERTER_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Converter {
public:
    bool fileExists(const string& fileName);
    void openFile();
    void openWrite(string line, bool tag);

};


#endif //HTMLCONVERTER_CONVERTER_H
