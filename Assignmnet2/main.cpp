#include <iostream>
#include <string>
#include "rational.h"

using namespace std;

int main() {
    //initialize the two user numbers
    RationalNum num1;
    RationalNum num2 = RationalNum(1,2);
    RationalNum num3;
    RationalNum num4;
    RationalNum num5;
    RationalNum num6;
    bool greaterThan;
    bool lessThan;
    bool equelToo;

    cout << "enter a rational number" << endl;
    cin >> num1;

    num3 = num1 + num2;
    num4 = num1 - num2;
    num5 = num1 * num2;
    num6 = num1 / num2;
    greaterThan = num1 > num2;
    lessThan = num1 < num2;
    equelToo = num1 == num2;



    cout << num1 << " + " << num2 << " = " << num3 << endl;
    cout << num1 << " - " << num2 << " = " << num4 << endl;
    cout << num1 << " * " << num2 << " = " << num5 << endl;
    cout << num1 << " / " << num2 << " = " << num6 << endl;
    cout << num1 << " > " << num2 << " = " << greaterThan << endl;
    cout << num1 << " < " << num2 << " = " << lessThan << endl;
    cout << num1 << " == " << num2 << " = " << equelToo << endl;

    return 0;
}