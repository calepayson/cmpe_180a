#include <iostream>

using std::cout;
using std::endl;

int main() {
    int *p;
    int num1 = 5;
    int num2 = 8;

    p = &num1;
    cout << "&num1 = " << &num1 << endl;
    cout << "p =     " << p << endl;
    cout << "num1 = " << num1 << endl;
    cout << "*p =   " << *p << endl;
    cout << endl;

    *p = 10;
    cout << "num1 = " << num1 << endl;
    cout << "*p =   " << *p << endl;
    cout << endl;

    p = &num2;
    cout << "&num2 = " << &num2 << endl;
    cout << "p =     " << p << endl;
    cout << "num2 = " << num2 << endl;
    cout << "*p =   " << *p << endl;
    cout << endl;

    *p = 2;
    cout << "num2 = " << num2 << endl;
    cout << "*p =   " << *p << endl;
    cout << endl;

    return 0;
}
