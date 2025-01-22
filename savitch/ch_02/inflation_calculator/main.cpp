#include <iostream>

int main() {
    std::cout << "Current price: $";
    double price{};
    std::cin >> price;

    std::cout << "Years until purchase: ";
    int years{};
    std::cin >> years;

    std::cout << "Rate of inflation: ";
    double inflation{};
    std::cin >> inflation;

    if (inflation > 1) inflation /= 100;  // convert to range [0, 1]

    while (years > 0) {
        price *= inflation + 1;
        years--;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout << "It will cost $" << price << '\n';

    return 0;
}
