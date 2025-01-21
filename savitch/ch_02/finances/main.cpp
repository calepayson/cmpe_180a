#include <iostream>

int main() {
    std::cout << "Savings: $";
    double savings{};
    std::cin >> savings;

    std::cout << "Expenses: $";
    double expenses{};
    std::cin >> expenses;

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    if (savings >= expenses) {
        savings -= expenses;
        expenses = 0;

        std::cout << "Savings: $" << savings << '\n';
        std::cout << "Expenses: $" << expenses << '\n';
        std::cout << "Solvent!\n";
    } else {
        std::cout << "Savings: $" << savings << '\n';
        std::cout << "Expenses: $" << expenses << '\n';
        std::cout << "Bankrupt!\n";
    }

    return 0;
}
