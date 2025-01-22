#include <iostream>

double get_face_value(double amount, double rate, double period) {
    return amount / (1 - rate * period);
}

double get_monthly_payment(double amount, double period) {
    return amount / (period * 12);
}

int main() {
    char proceed{'y'};

    while (proceed == 'y' || proceed == 'Y') {
        // Get desired amount from user
        std::cout << "Enter desired amount: $";
        double desired_amount{};
        std::cin >> desired_amount;

        // Get rate from user
        std::cout << "Enter rate: ";
        double rate{};
        std::cin >> rate;

        // Get period from user
        std::cout << "Enter period (years): ";
        double period{};
        std::cin >> period;

        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);

        double face_value{get_face_value(desired_amount, rate, period)};
        std::cout << "Face value of loan: $" << face_value << '\n';

        double monthly_payment{get_monthly_payment(face_value, period)};
        std::cout << "Monthly loan payment: $" << monthly_payment << '\n';

        std::cout << '\n';

        std::cout << "Proceed? (y/n) ";
        std::cin >> proceed;
    }

    return 0;
}
