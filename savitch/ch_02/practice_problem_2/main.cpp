#include <iostream>

int get_int() {
    int x{0};

    std::cout << "Enter a non-zero integer: ";
    std::cin >> x;

    return x;
}

int main() {
    std::cout << "Welcome to square root.\n"
              << "Available modes: \n"
              << "\t(1) Quick\n"
              << "\t(2) Precise\n"
              << "Enter an integer to choose the mode: ";
    int mode{};
    std::cin >> mode;

    if (mode == 1) {
        std::cout << "You chose (1) Quick!\n";
        int num{get_int()};
        std::cout << "Calculating square root of " << num << "...\n";
    } else if (mode == 2) {
        std::cout << "You chose (2) Precise!\n";
        int num{get_int()};
        std::cout << "Calculating square root of " << num << "...\n";
    } else {
        std::cout << "Error: mode (" << mode << ") not recognized!\n";
    }

    return 0;
}
