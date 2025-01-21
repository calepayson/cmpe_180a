#include <iostream>

int main() {
    const double LITERS_PER_GALLON{3.78533};

    std::cout << "Gallons: ";
    double gallons{};
    std::cin >> gallons;

    double liters{gallons * LITERS_PER_GALLON};
    std::cout << "Liters: " << liters << '\n';

    return 0;
}
