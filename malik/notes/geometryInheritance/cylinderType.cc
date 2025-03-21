#include "circleType.h"
#include "cylinderType.h"

void cylinderType::setHeight(const double &new_h) { h = new_h; }
void cylinderType::getHeight(double &new_h) const { new_h = h; }

void cylinderType::getArea(double &area) const {
    double end_area;
    double end_circumference;
    circleType::getArea(end_area);
    circleType::getCircumference(end_circumference);
    area = 2 * end_area + (end_circumference * h);
}
void cylinderType::getVolume(double &volume) const {
    double end_area;
    circleType::getArea(end_area);
    volume = end_area * h;
}

cylinderType::cylinderType() : circleType(), h(0) {}
cylinderType::cylinderType(const double &x, const double &y, const double &r,
                           const double &new_h)
    : circleType(x, y, r) {
    h = (new_h > 0) ? h : 0;
}
cylinderType::~cylinderType() {}
