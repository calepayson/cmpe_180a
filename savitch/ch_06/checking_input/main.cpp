// Program to demonstrate the functions new_line and get_input
#include <iostream>
#include <ostream>

using namespace std;

// Discards all the input remaining on the current input line.
// Also discards the '\n' at the end of the line.
// This version works only for input from the keyboard.
void new_line();

// Postcondition: The variable number has been given a value that
// the user approves of.
void get_int(int &number);

int main() {
    int n;

    get_int(n);
    cout << "Final value read in = " << n << endl << "End of demonstration.\n";

    return 0;
}

// Uses iostream
void new_line() {
    char symbol;
    do {
        cin.get(symbol);
    } while (symbol != '\n');
}

// Uses iostream
void get_int(int &number) {
    char ans;
    do {
        cout << "Enter input number: ";
        cin >> number;
        cout << "You entered " << number << ". Is that correct? (y/n): ";
        cin >> ans;
        new_line();
    } while ((ans != 'Y') && (ans != 'y'));
}
