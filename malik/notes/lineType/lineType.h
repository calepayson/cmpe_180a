//*****************************************************************************
// Author: Cale Smith
//
// class lineType
// This class specifies the members to implement a line in the form aX + bY = c
//*****************************************************************************

#ifndef LINETYPE_H
#define LINETYPE_H

class lineType {
   public:
    // Function to get the slope of a line
    // Postcondition: Returns the slope of the line.
    void getSlope(double &slope) const;

    // Function to check if two lines are equal.
    // Postcondition: Returns true if a == k * other.a, b = k * other.b, c = k *
    //     other.c where k is a constant that satisfies the conditions.
    //     Otherwise returns false.
    bool isEqual(const lineType &other) const;

    // Function to check if two lines are parallel
    // Postcondition: Returns true if getSlope() == other.getSlope(). Otherwise
    //     returns false.
    bool isParallel(const lineType &other) const;

    // Function to check if two lines are perpindicular
    // Postcondition: Returns true if -1 / getSlope() == other.getSlope().
    //     Otherwise returns false.
    bool isPerpendicular(const lineType &other) const;

    // Function to find the intersection of two lines
    // Postcondition: x_intersect, y_intersect = point of intersection.
    void intersection(const lineType &other, double &x_intersect,
                      double &y_intersect) const;

    // Default constructor
    // Sets all constants to 0.
    // Postcondition: a = 0; b = 0; c = 0;
    lineType();

    // Parameterized constructor
    // Sets the constants to the parameters.
    // Postcondition: a = setA; b = setB; c = setC
    lineType(double setA, double setB, double setC);

   private:
    double a;
    double b;
    double c;
};

#endif
