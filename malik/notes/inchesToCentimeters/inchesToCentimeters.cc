#include <iostream>

using std::cerr;
using std::endl;

// Precondition: The value of inches must be nonnegative.
// Postcondition: If the value of inches is < 0, the function returns -1.0;
//     otherwise, the function returns the equivalent length in centimeters.
double inchesToCentimeters(double inches) {
    if (inches < 0) {
        cerr << "The given measurement must be nonnegative." << endl;
        return -1.0;
    } else {
        return 2.54 * inches;
    }
}
