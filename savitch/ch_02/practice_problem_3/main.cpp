#include <iostream>

int main() {
    std::cout << "Enter a speed in mph: ";
    double speed{};
    std::cin >> speed;

    double pace = 60 / speed;
    int minutes = static_cast<int>(pace);
    double seconds = (pace - minutes) * 60;

    // Set floating point precision to one
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(1);

    std::cout << "Your pace is " << minutes << " minutes and " << seconds
              << " seconds!\n";

    return 0;
}
