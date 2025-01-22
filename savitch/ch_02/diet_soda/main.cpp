#include <iostream>

int main() {
    const int MASS_OF_SODA = 350;  // grams
    const double SWEETENER_PERCENTAGE = 0.001;

    std::cout << "----------------\n";
    std::cout << "- DOSE TRACKER -\n";
    std::cout << "----------------\n";
    std::cout << '\n';
    std::cout << "So you can poison yourself without poisoning yourself!\n";
    std::cout << '\n';

    // Get lethal dose
    std::cout << "Grams of sweetener to kill a mouse: ";
    double mouse_lethal_dose{};
    std::cin >> mouse_lethal_dose;

    // Get mass of mouse
    std::cout << "Mass of a mouse (grams): ";
    double mouse_mass{};
    std::cin >> mouse_mass;

    // Get mass of person
    std::cout << "Your weight (grams): ";
    double person_mass{};
    std::cin >> person_mass;

    double person_lethal_dose = person_mass * mouse_lethal_dose / mouse_mass;
    double sweetener_per_soda = MASS_OF_SODA * SWEETENER_PERCENTAGE;
    double sodas_before_death = person_lethal_dose / sweetener_per_soda;

    std::cout << "You can drink " << sodas_before_death
              << " sodas before dying.\n";

    return 0;
}
