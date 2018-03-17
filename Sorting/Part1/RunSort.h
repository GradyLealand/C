//
// Created by prog2100 on 15/03/18.
//

#ifndef PART1_RUNSORT_H
#define PART1_RUNSORT_H


#include "Sorter.h"
#include "Util.h"
#include <string>

using namespace std;

class RunSort {
private:
    Sorter sorter;
    Util util;
public:
    void sortAll(int size);
    void writeFile(string writeFile, string type, int a[], int size);
};


#endif //PART1_RUNSORT_H
