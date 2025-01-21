// File Name: main.cpp
// Author: Cale Payson
// Email Address: calepayson@mac.com
// Assignment Number: 2
// Description: Program to determine if the user is ill.
// Last Changed: 2024-01-21

#include <iostream>

using namespace std;

int main() {
    const double NORMAL = 98.6;  // Degrees Fahrenheit

    cout << "Enter your temperature: ";
    double temperature;
    cin >> temperature;

    if (temperature > NORMAL) {
        cout << "You have a fever.\n";
        cout << "Drink lots of liquids and get to bed.\n";
    } else {
        cout << "You don't have a fever.\n";
        cout << "Go study.\n";
    }

    return 0;
}
