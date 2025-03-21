#include <iostream>

#include "cylinderType.h"

using std::cout;
using std::endl;

int main() {
    cylinderType cylinder1;
    cylinderType cylinder2(0, 0, 1, 1);

    double area;
    double volume;
    cylinder2.getArea(area);
    cylinder2.getVolume(volume);

    cout << "A: " << area << endl;
    cout << "V: " << volume << endl;

    return 0;
}
