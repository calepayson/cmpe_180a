#include <iostream>

int main() {
    const double PAY_RAISE = 1.076;

    std::cout << "Previous annual salary: ";
    double previous_annual_salary{};
    std::cin >> previous_annual_salary;

    // Set output precision to two
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    double retroactive_pay =
        (previous_annual_salary * PAY_RAISE - previous_annual_salary) / 2;
    std::cout << "Retroactive pay: $" << retroactive_pay << '\n';

    double new_annual_salary = previous_annual_salary * PAY_RAISE;
    std::cout << "New annual salary: $" << new_annual_salary << '\n';

    double new_monthly_salary = new_annual_salary / 12;
    std::cout << "New monthly salary: $" << new_monthly_salary << '\n';

    return 0;
}
