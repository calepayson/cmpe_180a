#include "XYPoint.h"

XYPoint::XYPoint() : x(0), y(0) {}
XYPoint::XYPoint(double new_x, double new_y) : x(new_x), y(new_y) {}

void XYPoint::setX(double new_x) { x = new_x; }
void XYPoint::setY(double new_y) { y = new_y; }

double XYPoint::getX() const { return x; }
double XYPoint::getY() const { return y; }

XYPoint::~XYPoint() {}
