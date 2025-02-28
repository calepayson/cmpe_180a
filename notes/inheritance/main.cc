class XYPoint {
   public:
    XYPoint();
    XYPoint(double x, double y);
    XYPoint(const XYPoint &other);

    double get_x() const;
    double get_y() const;

    void set_x(double new_x);
    void set_y(double new_y);

   protected:
    double x;
    double y;
};

XYPoint::XYPoint() : x(0), y(0) {}
XYPoint::XYPoint(double new_x, double new_y) : x(new_x), y(new_y) {}
XYPoint::XYPoint(const XYPoint &other) : x(other.x), y(other.y) {};
double XYPoint::get_x() const { return x; }
double XYPoint::get_y() const { return y; }
void XYPoint::set_x(double new_x) { x = new_x; }
void XYPoint::set_y(double new_y) { x = new_y; }

class XYZPoint : public XYPoint {
   public:
    XYZPoint();
    XYZPoint(double x, double y, double new_z);
    XYZPoint(const XYZPoint &other);

    double get_z() const;

    void set_z(double new_z);

   private:
    double z;
};

XYZPoint::XYZPoint() : XYPoint(), z(0) {}
XYZPoint::XYZPoint(double x, double y, double new_z)
    : XYPoint(x, y), z(new_z) {}
XYZPoint::XYZPoint(const XYZPoint &other)
    : XYZPoint(other.x, other.y, other.z) {}
double XYZPoint::get_z() const { return z; }
void XYZPoint::set_z(double new_z) { z = new_z; }
