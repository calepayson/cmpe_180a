// Computes the size of a dog house that can be purchased given the user's
// budget.

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const double COST_PER_SQ_FT = 10.50;
    double budget, area, length_side;

    cout << "Enter the amount budgeted for your dog house $";
    cin >> budget;

    area = budget / COST_PER_SQ_FT;
    length_side = sqrt(area);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "For a price of $" << budget << '\n'
         << "I can build you a luxurious square dog house\n"
         << "that is " << length_side << " feet on each side.\n";

    return 0;
}
