#include <iostream>

#include "XYPoint.h"

int main() {
    using std::cout;
    using std::endl;

    XYPoint point_1;

    cout << "x: " << point_1.getX() << endl;
    cout << "y: " << point_1.getY() << endl;

    return 0;
}
