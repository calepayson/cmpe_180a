#include <iostream>

#include "circleType.h"

using std::cout;

void circleType::setRadius(const double &new_r) { r = new_r; }
void circleType::getRadius(double &new_r) const { new_r = r; }

void circleType::getArea(double &area) const { area = 3.14 * r * r; }
void circleType::getCircumference(double &circumference) const {
    circumference = 2 * 3.14 * r;
}

void circleType::print() const {
    pointType::print();
    cout << ", " << r;
}

circleType::circleType() : pointType(), r(0) {}
circleType::circleType(const double &x, const double &y, const double &new_r)
    : pointType(x, y), r(new_r) {}
circleType::~circleType() {}
