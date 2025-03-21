#ifndef POINTYPE_H
#define POINTYPE_H

class pointType {
   public:
    void getX(double &other_x) const;
    void getY(double &other_y) const;
    void getPoint(double &other_x, double &other_y) const;

    void setX(double new_x);
    void setY(double new_y);
    void setPoint(double new_x, double new_y);

    void print() const;

    pointType();
    pointType(double new_x, double new_y);
    virtual ~pointType();

   private:
    double x;
    double y;
};

#endif
