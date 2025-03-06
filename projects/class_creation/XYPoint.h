#ifndef XYPOINT_H
#define XYPOINT_H

/**
 * @class XYPoint
 * @brief Represents a point with x and y coordinates in a 2D space.
 */
class XYPoint {
   public:
    /**
     * @brief Default constructor.
     * @details Initializes a point at the origin (0, 0).
     */
    XYPoint();

    /**
     * @brief Paramatarized constructor.
     * @param new_x The x-coordinate of the point.
     * @param new_y The y-coordinate of the point.
     * @details Initializes a point at the specified coordinates.
     */
    XYPoint(double new_x, double new_y);

    /**
     * @brief Sets the x-coordinate of the point.
     * @param new_x The new x-coordinate of the point.
     */
    void setX(double new_x);

    /**
     * @brief Sets the y-coordinate of the point.
     * @param new_y The new y-coordinate of the point.
     */
    void setY(double new_y);

    /**
     * @brief Gets the x-coordinate of the point.
     * @return The current x-coordinate value.
     */
    double getX() const;

    /**
     * @brief Gets the y-coordinate of the point.
     * @return The current y-coordinate value.
     */
    double getY() const;

    /**
     * @brief Destructor.
     * @details Virtual destructor that performs no special cleanup as the class
     *          only contains primitive data types. Defined as virtual to
     *          support proper cleanup in derived classes.
     */
    virtual ~XYPoint();

   private:
    // The x-coordinate of the point.
    double x;
    // The y-coordinate of the point.
    double y;
};

#endif
