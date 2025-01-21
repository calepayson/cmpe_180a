#include <iostream>

int main() {
    double price = 78.50;

    std::cout << "Before: \n";
    std::cout << "price = $" << price << "\n\n";

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout << "After: \n";
    std::cout << "price = $" << price << '\n';

    return 0;
}
