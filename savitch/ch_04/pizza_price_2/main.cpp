#include <iostream>

using namespace std;

double price_per_inch(int diameter, double price);
double price_per_inch(int length, int width, double price);

int main() {
    int circular_pizza_diameter{};
    double circular_pizza_price{};
    int rectangular_pizza_length{};
    int rectangular_pizza_width{};
    double rectangular_pizza_price{};

    cout << "Circular Pizza Diameter: ";
    cin >> circular_pizza_diameter;
    cout << "Circular Pizza Price: $";
    cin >> circular_pizza_price;
    cout << "Rectangular Pizza Length: ";
    cin >> rectangular_pizza_length;
    cout << "Rectangular Pizza Width: ";
    cin >> rectangular_pizza_width;
    cout << "Rectangular Pizza Price: $";
    cin >> rectangular_pizza_price;

    double circular_price_per_inch =
        price_per_inch(circular_pizza_diameter, circular_pizza_price);
    double rectangular_price_per_inch =
        price_per_inch(rectangular_pizza_length, rectangular_pizza_width,
                       rectangular_pizza_price);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Circular pizza price per square inch: $" << circular_price_per_inch
         << '\n';
    cout << "Rectangular pizza price per square inch: $"
         << rectangular_price_per_inch << '\n';

    return 0;
}

double price_per_inch(int diameter, double price) {
    const double PI = 3.1415926535;
    double radius = static_cast<double>(diameter) / 2;
    double area = radius * radius * PI;
    return price / area;
}

double price_per_inch(int length, int width, double price) {
    return price / (length * width);
}
