#include <iostream>

#include "pointType.h"

using std::cout;
using std::endl;

int main() {
    pointType point1;
    pointType point2(1, 2);

    point1.print();
    cout << endl;
    point2.print();
    cout << endl;

    return 0;
}
