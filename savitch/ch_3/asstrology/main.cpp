#include <iostream>

int main() {
    std::cout << "Please enter your birthday!\n";
    std::cout << "Month (1-12): ";
    int birth_month{};
    std::cin >> birth_month;
    std::cout << "Day (1-31): ";
    int birth_date{};
    std::cin >> birth_date;

    std::cout << "Your birthday is: " << birth_month << '-' << birth_date
              << '\n';

    return 0;
}
