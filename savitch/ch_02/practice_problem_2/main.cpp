#include <iostream>

double get_double() {
    double x{0};

    std::cout << "Enter a number: ";
    std::cin >> x;

    return x;
}

double quick_sqrt(double num) {
    const int LIMIT{100};
    int counter{0};
    double guess{num / 2};
    double r{};

    while (counter < LIMIT) {
        r = num / guess;
        guess = (guess + r) / 2;
        counter++;
    }

    return guess;
}

double precise_sqrt(double num) {
    double previous_guess{};
    double current_guess{num / 2};
    double r{};

    double similarity{0};

    while (similarity < 0.99 || similarity > 1.01) {
        previous_guess = current_guess;
        r = num / current_guess;
        current_guess = (current_guess + r) / 2;

        similarity = previous_guess / current_guess;
    }

    return current_guess;
}

int main() {
    std::cout << "Welcome to square root.\n"
              << "Available modes: \n"
              << "\t(1) Quick\n"
              << "\t(2) Precise\n"
              << "Enter an integer to choose the mode: ";
    int mode{};
    std::cin >> mode;

    // Set floating point precision to four
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);

    if (mode == 1) {
        std::cout << "You chose (1) Quick!\n";
        double num{get_double()};
        std::cout << "Calculating square root of " << num << "...\n";
        double result{quick_sqrt(num)};
        std::cout << "The square root of " << num << " is " << result << '\n';
    } else if (mode == 2) {
        std::cout << "You chose (2) Precise!\n";
        double num{get_double()};
        std::cout << "Calculating square root of " << num << "...\n";
        double result{precise_sqrt(num)};
        std::cout << "The square root of " << num << " is " << result << '\n';
    } else {
        std::cout << "Error: mode (" << mode << ") not recognized!\n";
    }

    return 0;
}
