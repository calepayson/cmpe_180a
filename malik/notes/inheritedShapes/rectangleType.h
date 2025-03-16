//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// class rectangleType
// This class specifies the memebers to implement the properties of a rectangle
//*****************************************************************************

#ifndef RECTANGLETYPE_H
#define RECTANGLETYPE_H

class rectangleType {
   public:
    // Function to set the length and width of the rectangle.
    // Postcondition: length = 1; width = w;
    void setDimension(double l, double w);

    // Function to get the length of a rectangle
    // Postcondition: The value of length is returned.
    double getLength() const;

    // Function to get the width of a rectangle
    // Postcondition: The value of width is returned;
    double getWidth() const;

    // Function to get the area of a rectangle
    // Postcondition: Returns length * width
    double getArea() const;

    // Function to get the perimeter of a rectangle
    // Postcondition: Returns 2 * (length + width)
    double getPerimeter() const;

    // Function to output the length and width of the rectangle
    void print() const;

    // Default constructor
    // Postcondition: initializes length and width to 0;
    rectangleType();

    // Parameterized constructor
    // Postcondition: Sets length = l; width = w
    rectangleType(double l, double w);

   private:
    double length;
    double width;
};

#endif
