#include <iostream>

#include "rectangleType.h"

using std::cout;
using std::ostream;

void rectangleType::setDimension(double l, double w) {
    length = l;
    width = w;
}

double rectangleType::getLength() const { return length; }

double rectangleType::getWidth() const { return width; }

double rectangleType::getArea() const { return length * width; }

double rectangleType::getPerimeter() const { return 2 * (length + width); }

void rectangleType::print() const { cout << length << ", " << width; }

rectangleType rectangleType::operator+(const rectangleType &other) const {
    rectangleType tempRect;

    tempRect.length = length + other.length;
    tempRect.width = width + other.width;

    return tempRect;
}

rectangleType rectangleType::operator*(const rectangleType &other) const {
    rectangleType tempRect;

    tempRect.length = length + other.length;
    tempRect.width = width + other.width;

    return tempRect;
}

bool rectangleType::operator==(const rectangleType &other) const {
    return (width == other.width && length == other.length);
}

bool rectangleType::operator!=(const rectangleType &other) const {
    return !(*this == other);
}

ostream &operator<<(ostream &out, const rectangleType &rect) {
    out << "Length = " << rect.length << "; Width = " << rect.width;
    return out;
}

istream &operator>>(istream &in, rectangleType &rect) {
    in >> rect.length >> rect.width;
    return in;
}

rectangleType::rectangleType() : length(0), width(0) {}

rectangleType::rectangleType(double l, double w) : length(l), width(w) {}
