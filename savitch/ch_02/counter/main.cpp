#include <iostream>

int main() {
    int counter{1};
    int limit{20};

    while (counter <= limit) std::cout << counter++ << '\n';

    return 0;
}
