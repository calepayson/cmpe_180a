#include <iostream>

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(1);

    double c{20};
    double f;
    f = (9.0 / 5.0) * c + 32.0;

    std::cout << "20.0C -> " << f << "F\n";

    return 0;
}
