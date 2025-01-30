#include <iostream>

int main() {
    int random_num = random() % 10;
    int random_num2 = random() % 10;

    std::cout << "The number is: " << random_num << '\n';
    std::cout << "The number is: " << random_num2 << '\n';

    return 0;
}
