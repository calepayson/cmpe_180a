#include <iostream>

int main() {
    const double OUNCES_PER_TON{35273.92};

    std::cout << "Enter the weight of a package of cereal in ounces: ";
    double ounces{};
    std::cin >> ounces;

    double tons{ounces / OUNCES_PER_TON};
    std::cout << "One box of cereal weighs " << tons << " metric tons.\n";

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    double boxes_per_ton{1 / tons};
    std::cout << boxes_per_ton << " boxes needed to yield 1 metric ton.\n";

    return 0;
}
