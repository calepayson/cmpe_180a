#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "declaration.h"

/***********
 * XYPoint *
 ***********/
XYPoint::XYPoint() : x(0), y(0) {}
XYPoint::XYPoint(double new_x, double new_y) : x(new_x), y(new_y) {}

void XYPoint::setX(double new_x) { x = new_x; }
void XYPoint::setY(double new_y) { y = new_y; }

double XYPoint::getX() const { return x; }
double XYPoint::getY() const { return y; }

XYPoint::~XYPoint() {}

/**********
 * Circle *
 **********/
Circle::Circle(const XYPoint &center, double radius) : c(center), r(radius) {}
double Circle::area() const { return 3.141592653 * r * r; }

/************
 * Triangle *
 ************/
Triangle::Triangle(const XYPoint &point1, const XYPoint &point2,
                   const XYPoint &point3)
    : p1(point1), p2(point2), p3(point3) {}
double Triangle::area() const {
    return std::abs(p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())) /
           2.0;
}

/*************
 * Rectangle *
 *************/
Rectangle::Rectangle(const XYPoint &point1, const XYPoint &point2,
                     const XYPoint &point3, const XYPoint &point4)
    : p1(point1), p2(point2), p3(point3), p4(point4) {}
double Rectangle::distance(const XYPoint &a, const XYPoint &b) const {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return std::sqrt(dx * dx + dy * dy);
}
double Rectangle::area() const {
    double d12 = distance(p1, p2);
    double d23 = distance(p2, p3);
    double d34 = distance(p3, p4);
    double d41 = distance(p4, p1);
    double d13 = distance(p1, p3);
    double d24 = distance(p2, p4);

    std::vector<double> sides = {d12, d23, d34, d41, d13, d24};
    std::sort(sides.begin(), sides.end());

    return sides[0] * sides[2];
}

/***************
 * ShapeSorter *
 ***************/
void ShapeSorter(std::vector<Shape *> &shapes) {
    std::sort(shapes.begin(), shapes.end(),
              [](Shape *a, Shape *b) { return a->area() < b->area(); });
}
