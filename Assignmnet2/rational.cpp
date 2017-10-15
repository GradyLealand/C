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
}//end RationalNum default

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

string RationalNum::multiply(int num1, int nom1, int num2, int nom2){
    int answerNum = (num1 * num2);
    int answerNom = (nom1 * nom2);
    string answeString = to_string(answerNum) + "/" + to_string(answerNom);

    return answeString;
}

string RationalNum::divide(RationalNum num1, RationalNum num2) {

}



