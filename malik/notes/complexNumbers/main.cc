//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// This program show how to use the class complexType.
//*****************************************************************************

#include <iostream>

#include "complexNumber.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    complexType num1(23, 34);
    complexType num2;
    complexType num3;

    cout << "Line 20: Num1 = " << num1 << endl;
    cout << "Line 21: Num2 = " << num2 << endl;

    cout << "Line 23: Enter the complex number in the form (a, b): ";
    cin >> num2;
    cout << endl;

    num3 = num1 + num2;

    cout << "Line 29: Num3 = " << num3 << endl;

    cout << "Line 31: " << num1 << " * " << num2 << " = " << num1 * num2
         << endl;

    return 0;
}
