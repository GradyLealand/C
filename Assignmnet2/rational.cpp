//
// Created by grady williams on 11/10/17.
//

#include "rational.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

RationalNum::RationalNum()
{
    //Set number to one if nothing specified
    numerator = 1;
    denominator = 1;
}

//end RationalNum default

RationalNum::RationalNum(int nume, int denom) {
    //if a fraction is entered set numerator and denominator as entered by user
    numerator = nume;
    denominator = denom;
}//end RationalNum for fraction

RationalNum::RationalNum(int nume) {
    //if a whole number is entered set numerator to the users number and denominator to 1
    numerator = nume;
    denominator = 1;
}//end RationalNum for whole number

void RationalNum::checkNumber(string) {

}


//----Getters and setters----
int RationalNum::getNumerator() const {
    return numerator;
}

void RationalNum::setNumerator(int numerator) {
    RationalNum::numerator = numerator;
}

int RationalNum::getDenominator() const {
    return denominator;
}

void RationalNum::setDenominator(int denominator) {
    RationalNum::denominator = denominator;
}

//----overload functions----
RationalNum RationalNum::operator + ( RationalNum &rightObj){
    RationalNum sum;
    sum.setNumerator((this->numerator * rightObj.getDenominator()) + (this->denominator * rightObj.getNumerator())) ;
    sum.setDenominator(this->denominator * rightObj.getDenominator());
    return sum;
}

RationalNum RationalNum::operator- (RationalNum &rightObj){
    RationalNum sum;
    sum.setNumerator((this->numerator * rightObj.denominator) - (this->denominator * rightObj.numerator)) ;
    sum.setDenominator(this->denominator * rightObj.denominator);
    return sum;
}

RationalNum RationalNum::operator* (RationalNum &rightObj){
    RationalNum sum;
    sum.setNumerator(this->numerator * rightObj.numerator);
    sum.setDenominator(this->denominator * rightObj.denominator);
    return sum;
}

RationalNum RationalNum::operator/ (RationalNum &rightObj){
    RationalNum sum;
    sum.setNumerator(this->numerator * rightObj.denominator);
    sum.setDenominator(this->denominator * rightObj.numerator) ;
    return sum;
}

bool RationalNum::operator> (RationalNum &rightObj){
    float numOne = (float)this->getNumerator()/ (float)this->getDenominator();
    float numTwo = (float)rightObj.getNumerator() / (float)rightObj.getDenominator();
    return numOne > numTwo;
}

bool RationalNum::operator< (RationalNum &rightObj){
    float numOne = (float)this->getNumerator()/ (float)this->getDenominator();
    float numTwo = (float)rightObj.getNumerator() / (float)rightObj.getDenominator();
    return numOne < numTwo;
}

bool RationalNum::operator== (RationalNum &rightObj){
    float numOne = (float)this->getNumerator()/ (float)this->getDenominator();
    float numTwo = (float)rightObj.getNumerator() / (float)rightObj.getDenominator();
    return numOne == numTwo;
}

ostream& RationalNum::operator << (ostream& outs, RationalNum &num){
    int nume;
    int denom;
    nume = num.getNumerator();
    denom = num.getDenominator();
    outs << nume << '/' << denom ;

    return outs;
}

istream RationalNum::operator >> (istream &input, RationalNum &num){
    int TopNumber;
    int BottomNumber;
    char one_char;

    input >> TopNumber;
    input >> one_char;
    if (one_char == '/')
    {
        input >> BottomNumber;
    }
    else
    {
        BottomNumber = 1;
    }
    num.numerator = TopNumber;
    num.denominator = BottomNumber;
    return input;
}






