#include <iostream>

int main() {
    int quarters{0};
    int dimes{0};
    int nickels{0};

    std::cout << "Please enter the number of each coin you have.\n";

    std::cout << "Quarters: ";
    std::cin >> quarters;

    std::cout << "Dimes: ";
    std::cin >> dimes;

    std::cout << "Nickels: ";
    std::cin >> nickels;

    int total{(quarters * 25) + (dimes * 10) + (nickels * 5)};
    int total_dollars{total / 100};
    int total_cents{total % 100};

    std::cout << "You are worth: $" << total_dollars << '.' << total_cents
              << '\n';
    std::cout << "Good luck!\n";

    return 0;
}
