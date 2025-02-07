#include <iostream>
#include <string>

#include "avg.h"

using std::cerr;
using std::cout;
using std::endl;

#include "avg.h"

double avg(double a, double b, double c) { return (a + b + c) / 3; }

int main() {
    std::string s1("string1"), s2("string2");

    cout << s1 + s2 << endl;

    cout << "avg(2, 4) = " << avg(2, 4) << endl;
    cout << "avg(2, 4, 8) = " << avg(2, 4, 8) << endl;

    return 0;
}
