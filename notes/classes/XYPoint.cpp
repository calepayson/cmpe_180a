#include "XYPoint.h"

XYPoint::XYPoint() {
    x = 0;
    y = 0;
}

/*XYPoint(double new_x, double new_y);*/
XYPoint::XYPoint(double new_x, double new_y) {
    x = new_x;
    y = new_y;
}

/*XYPoint(XYPoint &other_point);*/
XYPoint::XYPoint(const XYPoint &other_point) {
    x = other_point.x;
    y = other_point.y;
}

/*~XYPoint();*/
XYPoint::~XYPoint() {}

/*void setX(double x);*/
void XYPoint::setX(double new_x) { x = new_x; }

/*void setY(double y);*/
void XYPoint::setY(double new_y) { y = new_y; }

/*double getX();*/
double XYPoint::getX() const { return x; }

/*double getY();*/
double XYPoint::getY() const { return y; }
