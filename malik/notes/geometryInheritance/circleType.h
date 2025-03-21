#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H

#include "pointType.h"

class circleType : public pointType {
   public:
    void setRadius(const double &new_r);
    void getRadius(double &r) const;

    void getArea(double &area) const;
    void getCircumference(double &circumference) const;

    void print() const;

    circleType();
    circleType(const double &x, const double &y, const double &new_r);
    virtual ~circleType();

   private:
    double r;
};

#endif
