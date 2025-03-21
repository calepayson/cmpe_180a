#ifndef CYLINDER_TYPE
#define CYLINDER_TYPE

#include "circleType.h"

class cylinderType : public circleType {
   public:
    void setHeight(const double &new_h);
    void getHeight(double &new_h) const;

    void getArea(double &area) const;
    void getVolume(double &volume) const;

    cylinderType();
    cylinderType(const double &x, const double &y, const double &r,
                 const double &new_height);
    virtual ~cylinderType();

   private:
    double h;
};

#endif
