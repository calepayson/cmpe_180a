#include <iostream>

int main() {
    const double OUNCES_PER_TON{35273.92};

    char status{'y'};

    while (status == 'y' || status == 'Y') {
        std::cout << "Enter the weight of a package of cereal in ounces: ";
        double ounces{};
        std::cin >> ounces;

        // Set precision to 8
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(8);

        double tons{ounces / OUNCES_PER_TON};
        std::cout << "One box of cereal weighs " << tons << " metric tons.\n";

        // Set precision to 2
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);

        double boxes_per_ton{1 / tons};
        std::cout << boxes_per_ton << " boxes needed to yield 1 metric ton.\n";

        std::cout << "Continue? (y/n): ";
        std::cin >> status;
    }

    return 0;
}
