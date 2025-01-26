// Illustrate overloading a function
#include <iostream>

double ave(double n1, double n2);
// Returns the average of the two numbers n1 and n2.

double ave(double n1, double n2, double n3);
// Returns the average of the three numbers n1, n2, and n3.

int main() {
    using namespace std;

    double num1{2.0};
    double num2{2.5};
    double num3{3.0};

    cout << "The average of " << num1 << " and " << num2
         << " is: " << ave(num1, num2) << '\n';

    cout << "The average of " << num1 << ", " << num2 << ", and " << num3
         << " is: " << ave(num1, num2, num3) << '\n';

    return 0;
}

double ave(double n1, double n2) { return (n1 + n2) / 2; }

double ave(double n1, double n2, double n3) { return (n1 + n2 + n3) / 3; }
