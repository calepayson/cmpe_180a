#include <fstream>
#include <iostream>

int main() {
    std::ifstream fin;
    int min, max;

    fin.open("nums.txt");
    if (fin.fail()) {
        std::cout << "Error opening file.\n";
        exit(1);
    }

    fin >> min;
    max = min;

    int next;
    while (fin >> next) {
        if (next > max) max = next;
        if (next < min) min = next;
    }

    std::cout << "Largest: " << max << '\n';
    std::cout << "Smallest: " << min << '\n';

    return 0;
}
