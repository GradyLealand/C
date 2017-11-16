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
private:
    string readFile;
    string writeFile;
public:
    bool fileExists(const string& fileName);
    string requestOpenFile();
    string requestWriteFile();
    void openFile(string fileRead, string fileWrite);
    void openWrite(string file, string line, bool tag);

    const string &getReadFile() const;

    void setReadFile(const string &readFile);

    const string &getWriteFile() const;

    void setWriteFile(const string &writeFile);

};


#endif //HTMLCONVERTER_CONVERTER_H
