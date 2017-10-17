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
    RationalNum operator + (RationalNum &rightObj);
    RationalNum operator - (RationalNum &rightObj);
    RationalNum operator / (RationalNum &rightObj);
    RationalNum operator * (RationalNum &rightObj);
    bool operator > (RationalNum &rightObj);
    bool operator < (RationalNum &rightObj);
    bool operator == (RationalNum &rightObj);
    friend ostream& operator << (ostream& outs, RationalNum &num);
    friend istream& operator >> (istream &input, RationalNum &num);

    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);

};


#endif //ASSIGNMNET2_RATIONAL_H
