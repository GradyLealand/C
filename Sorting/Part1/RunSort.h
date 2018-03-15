//
// Created by prog2100 on 15/03/18.
//

#ifndef PART1_RUNSORT_H
#define PART1_RUNSORT_H


#include "Sorter.h"
#include "Util.h"

class RunSort {
private:
    Sorter sorter;
    Util util;
public:
    void sortAll(int size);
};


#endif //PART1_RUNSORT_H
