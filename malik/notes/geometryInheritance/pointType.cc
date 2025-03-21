#include <iostream>

#include "pointType.h"

using std::cout;

void pointType::getX(double &other_x) const { other_x = x; }
void pointType::getY(double &other_y) const { other_y = x; }
void pointType::getPoint(double &other_x, double &other_y) const {
    other_x = x;
    other_y = y;
}

void pointType::setX(double new_x) { x = new_x; }
void pointType::setY(double new_y) { x = new_y; }
void pointType::setPoint(double new_x, double new_y) {
    x = new_x;
    y = new_y;
}

void pointType::print() const { cout << "(" << x << ", " << y << ")"; }

pointType::pointType() : x(0), y(0) {}
pointType::pointType(double new_x, double new_y) : x(new_x), y(new_y) {}
pointType::~pointType() {}
