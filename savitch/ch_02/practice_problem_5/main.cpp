#include <iostream>

using namespace std;

int main() {
    double radius, vm;
    cout << "Enter radius of a sphere: ";
    cin >> radius;
    vm = (4.0 / 3.0) * 3.1415 * radius * radius * radius;
    cout << " The volume is " << vm << endl;

    return 0;
}
