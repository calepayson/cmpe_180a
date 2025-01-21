#include <iostream>

int main() {
    double balance_owed{50.00};
    double interest_rate{0.02};
    double limit{100.0};
    int count{0};

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout << "Balance owed: $" << balance_owed << '\n';
    std::cout << "Interest rate: " << int(interest_rate * 100) << "%\n";
    std::cout << "Limit: $" << limit << '\n';

    while (balance_owed <= limit) {
        balance_owed += interest_rate * balance_owed;
        count++;

        std::cout << "Month " << count << " balance: $" << balance_owed << '\n';
    }

    std::cout << "\nLimit exceeded after " << count << " months!\n";

    return 0;
}
