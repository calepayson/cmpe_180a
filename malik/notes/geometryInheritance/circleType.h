#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H

#include "pointType.h"

class circleType : public pointType {
   public:
    void setRadius(double r);
    void getRadius(double &r) const;

    void getArea(double &area) const;
    void getCircumference(double &circumference) const;

    void print() const;

    circleType();
    circleType(double x, double y, double r);
    virtual ~circleType();

   private:
    double r;
};

#endif
