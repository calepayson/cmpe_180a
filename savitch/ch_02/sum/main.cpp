#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int x{0};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{0};
    std::cin >> y;

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
