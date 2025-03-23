#include <iostream>
#include <string>

#include "arrayListType.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    arrayListType<int> intList(100);
    arrayListType<string> stringList;

    int number;
    cout << "Enter 5 integers: ";
    for (int counter = 0; counter < 5; counter++) {
        cin >> number;
        intList.insertAt(counter, number);
    }

    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;

    string str;
    cout << "Enter 5 strings: ";
    for (int counter = 0; counter < 5; counter++) {
        cin >> str;
        stringList.insertAt(counter, str);
    }
    cout << endl;

    cout << endl;
    cout << "The lis tyou entered is: ";
    stringList.print();
    cout << endl;

    return 0;
}
