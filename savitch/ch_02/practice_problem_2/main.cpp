#include <iostream>

int main() {
    std::cout << "Welcome to square root.\n"
              << "Available modes: \n"
              << "\t(1) Quick\n"
              << "\t(2) Precise\n"
              << "Enter an integer to choose the mode: ";
    int mode{};
    std::cin >> mode;

    std::cout << "You chose (" << mode << ")\n";

    return 0;
}
