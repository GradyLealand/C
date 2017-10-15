//
// Created by prog2100 on 11/10/17.
//

#ifndef ASSIGNMNET2_RATIONAL_H
#define ASSIGNMNET2_RATIONAL_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class RationalNum {
private:
    int numerator;
    int denominator;

public:
    RationalNum();
    RationalNum(int, int);
    RationalNum(int);
    void checkNumber(string);
    string multiply(int, int, int, int);
    string divide(RationalNum, RationalNum);
    string add(RationalNum, RationalNum);
    string minus(RationalNum, RationalNum);

};


#endif //ASSIGNMNET2_RATIONAL_H
