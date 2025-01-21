#include <iostream>

int main() {
    double one{1.000}, two{1.414}, three{1.732}, four{2.000}, five{2.236};

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);

    std::cout << "N\tSquare Root\n";
    std::cout << "1\t" << one << '\n';
    std::cout << "2\t" << two << '\n';
    std::cout << "3\t" << three << '\n';
    std::cout << "4\t" << four << '\n';
    std::cout << "5\t" << five << '\n';

    return 0;
}
