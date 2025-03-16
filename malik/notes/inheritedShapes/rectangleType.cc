#include <iostream>

#include "rectangleType.h"

using std::cout;

void rectangleType::setDimension(double l, double w) {
    length = l;
    width = w;
}

double rectangleType::getLength() const { return length; }

double rectangleType::getWidth() const { return width; }

double rectangleType::getArea() const { return length * width; }

double rectangleType::getPerimeter() const { return 2 * (length + width); }

void rectangleType::print() const { cout << length << ", " << width; }

rectangleType::rectangleType() : length(0), width(0) {}

rectangleType::rectangleType(double l, double w) : length(l), width(w) {}
