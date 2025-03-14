#include "lineType.h"

void lineType::getSlope(double &slope) const {
    if (a == 0 || b == 0) {
        slope = 0;
        return;
    }

    slope = -(a / b);
}

bool lineType::isEqual(const lineType &other) const {
    if (a == 0 || b == 0 || c == 0 || other.a == 0 || other.b == 0 ||
        other.c == 0)
        return false;
    double k = a / other.a;
    return (a == k * other.a) && (b == k * other.b) && (c == k * other.c);
}

bool lineType::isParallel(const lineType &other) const {
    double slope1, slope2;
    getSlope(slope1);
    other.getSlope(slope2);
    return slope1 == slope2;
}

bool lineType::isPerpendicular(const lineType &other) const {
    double slope1, slope2;
    getSlope(slope1);
    other.getSlope(slope2);
    if (slope1 == 0 || slope2 == 0) return false;
    return slope1 == (-1 / slope2);
}

void lineType::intersection(const lineType &other, double &x_intersect,
                            double &y_intersect) const {
    if (a == 0 || b == 0 || c == 0 || other.a == 0 || other.b == 0 ||
        other.c == 0) {
        x_intersect = 0;
        y_intersect = 0;
    }

    double k = -other.a / a;

    y_intersect = (other.c + k * c) / (other.b + k * b);
    x_intersect = (c - (b * y_intersect)) / a;
}

lineType::lineType() : a(0), b(0), c(0) {}
lineType::lineType(double setA, double setB, double setC)
    : a(setA), b(setB), c(setC) {}
