#ifndef __XYPOINT_H__
#define __XYPOINT_H__

class XYPoint {
   public:
    XYPoint();
    XYPoint(double new_x, double new_y);
    XYPoint(const XYPoint &other_point);

    ~XYPoint();

    void setX(double new_x);
    void setY(double new_y);

    double getX();
    double getY();

   private:
    double x;
    double y;
};

#endif
