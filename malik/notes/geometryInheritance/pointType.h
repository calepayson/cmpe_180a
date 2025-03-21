#ifndef POINTYPE_H
#define POINTYPE_H

class pointType {
   public:
    void getX(double &x) const;
    void getY(double &y) const;
    void getPoint(double &x, double &y) const;

    void setX(double x);
    void setY(double y);
    void setPoint(double x, double y);

    void print() const;

    pointType();
    pointType(double new_x, double new_y);
    virtual ~pointType();

   private:
    double x;
    double y;
};

#endif
