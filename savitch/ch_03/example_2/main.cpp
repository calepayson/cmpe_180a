// Program to illustrate the switch statement.

#include <iostream>

using namespace std;

int main() {
    char grade;
    cout << "Enter your midterm grade and press Return: ";
    cin >> grade;

    switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent. You need not take the final.\n";
            break;
        case 'B':
        case 'b':
            cout << "Very good. ";
            grade = 'A';
            cout << "Your midterm grade is now " << grade << endl;
            break;
        case 'C':
        case 'c':
            cout << "Passing.\n";
            break;
        case 'D':
        case 'd':
        case 'F':
        case 'f':
            cout << "Not good. Go study.\n";
            break;
        default:
            cout << "That is not a possible grade.\n";
    }

    cout << "End of program.\n";
    return 0;
}
