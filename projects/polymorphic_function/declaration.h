#ifndef DECLARATION_H
#define DECLARATION_H

/***********
 * XYPoint *
 ***********/
class XYPoint {
   public:
    // Constructors
    XYPoint();
    XYPoint(double new_x, double new_y);

    // Methods
    void setX(double new_x);
    void setY(double new_y);
    double getX() const;
    double getY() const;

    // Destructor
    virtual ~XYPoint();

   private:
    double x;
    double y;
};

/*********
 * Shape *
 *********/
class Shape {
   public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

/**********
 * Circle *
 **********/
class Circle : public Shape {
   public:
    Circle(const XYPoint &center, double radius);
    double area() const;

   private:
    XYPoint c;
    double r;
};

/************
 * Triangle *
 ************/
class Triangle : public Shape {
   public:
    Triangle(const XYPoint &point1, const XYPoint &point2,
             const XYPoint &point3);
    double area() const;

   private:
    XYPoint p1, p2, p3;
};

/*************
 * Rectangle *
 *************/
class Rectangle : public Shape {
   public:
    Rectangle(const XYPoint &point1, const XYPoint &point2,
              const XYPoint &point3, const XYPoint &point4);
    double area() const;

   private:
    XYPoint p1, p2, p3, p4;
    double distance(const XYPoint &a, const XYPoint &b) const;
};

#endif
