#include <iostream>
#include <string>
#include "rational.h"

using namespace std;

int main() {
    //initialize the two user numbers
    RationalNum numOne;
    RationalNum numTwo;

    string multiplyAnswer = numOne.multiply(1,2,1,2);
    cout << multiplyAnswer << endl;
    string divideAnswer = numOne.divide(numOne, numTwo);
    return 0;
}