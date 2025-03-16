#include <iostream>

#include "boxType.h"

using std::cout;

void boxType::setDimension(double l, double w, double h) {
    rectangleType::setDimension(l, w);
    height = (l >= 0) ? l : 0;
}

double boxType::getHeight() const { return height; }

double boxType::getArea() const {
    return 2 * ((getLength() * getWidth()) + (getLength() * height) +
                (getWidth() * height));
}

double boxType::getVolume() const { return getLength() * getWidth() * height; }

void boxType::print() const {
    rectangleType::print();
    cout << ", " << height;
}

boxType::boxType() : rectangleType(), height(0) {}

boxType::boxType(double l, double w, double h)
    : rectangleType(l, w), height(h) {}
