#include <iostream>

using namespace std;

double price_per_inch(int diameter, double price);

int main() {
    int large_pizza_diameter{};
    double large_pizza_price{};
    int small_pizza_diameter{};
    double small_pizza_price{};

    cout << "Large Pizza Diameter: ";
    cin >> large_pizza_diameter;
    cout << "Large Pizza Price: $";
    cin >> large_pizza_price;
    cout << "Small Pizza Diameter: ";
    cin >> small_pizza_diameter;
    cout << "Small Pizza Price: $";
    cin >> small_pizza_price;

    double large_price_per_inch =
        price_per_inch(large_pizza_diameter, large_pizza_price);
    double small_price_per_inch =
        price_per_inch(small_pizza_diameter, small_pizza_price);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Large pizza price per square inch: $" << large_price_per_inch
         << '\n';
    cout << "Small pizza price per square inch: $" << small_price_per_inch
         << '\n';

    return 0;
}

double price_per_inch(int diameter, double price) {
    const double PI = 3.1415926535;
    double radius = static_cast<double>(diameter) / 2;
    double area = radius * radius * PI;
    return price / area;
}
