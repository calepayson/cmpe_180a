#include <iostream>

int main() {
    char proceed{'y'};

    while (proceed == 'y' || proceed == 'Y') {
        std::cout << "Maximum room capacity: ";
        int capacity{};
        std::cin >> capacity;

        std::cout << "Number of people: ";
        int current_people{};
        std::cin >> current_people;

        if (current_people > capacity) {
            std::cout << "You are in violation!\n";
            int people_to_exclude{current_people - capacity};
            std::cout << people_to_exclude << " people must exit the room.\n";
        } else {
            std::cout << "You may continue... But I've got my eye on you.\n";
            int remaining_spaces{capacity - current_people};
            std::cout << "Only " << remaining_spaces
                      << " more people may enter the room.\n";
        }

        std::cout << "Proceed? (y/n) ";
        std::cin >> proceed;
    }

    return 0;
}
