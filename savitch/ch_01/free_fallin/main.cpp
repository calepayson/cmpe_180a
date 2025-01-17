#include <iostream>

float distance(float acceleration, float time) {
    return acceleration * time * time * 0.5;
}

int main() {
    std::cout << "How long has Tom Petty been free fallin'?\n";
    std::cout << "Seconds: ";
    float time{};
    std::cin >> time;

    float acceleration{32.0};
    std::cout << "While free fallin', Tom Petty has travelled: "
              << distance(acceleration, time) << " feet.\n";
    std::cout << "Good luck Tom!\n";

    return 0;
}
