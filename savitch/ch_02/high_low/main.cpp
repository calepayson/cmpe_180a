#include <iostream>

int main() {
    std::cout << "Enter a score: ";
    int score{};
    std::cin >> score;

    if (score > 100)
        std::cout << "High!\n";
    else
        std::cout << "Low!\n";

    return 0;
}
