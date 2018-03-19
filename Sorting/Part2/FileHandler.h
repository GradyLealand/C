//
// Created by prog2100 on 19/03/18.
//

#ifndef PART2_FILEHANDLER_H
#define PART2_FILEHANDLER_H
#include<string>

using namespace std;

class FileHandler {
private:
    fstream *_if1;
    fstream *_if2;
    fstream *_if3;
    fstream *_if4;

    fstream *_of1;
    fstream *_of2;
    fstream *_of3;
    fstream *_of4;

    string basePath;
public:
    FileHandler();
    void splitFile(string fileOne, string fileTwo, string dataFile);
};


#endif //PART2_FILEHANDLER_H
