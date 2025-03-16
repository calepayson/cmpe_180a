//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// class boxType
// This class is derived from the class rectangleType and it specifies the
// members to implement the properties of a box.
//*****************************************************************************

#ifndef BOXTYPE_H
#define BOXTYPE_H

#include "rectangleType.h"

class boxType : public rectangleType {
   public:
    // Function to set the length, width, and height of the box.
    // Postcondition: length = l; width = w; height = h;
    void setDimension(double l, double w, double h);

    // Function to get the height of a box.
    // Postcondtion: The value of height is returned.
    double getHeight() const;

    // Function to get the area of a box.
    // Postcondition: the area of the box is calculated and returned.
    double getArea() const;

    // Function to get the volume of a box.
    // Postcondition: The volume of the box is calculated and returned.
    double getVolume() const;

    // Function to output the length, width, and height of the box.
    void print() const;

    // Default constructor
    // Postcondition: length = 0; width = 0; height = 0;
    boxType();

    // Parameterized constructor
    // Postcondition: length = l; width = w; height = h;
    boxType(double l, double w, double h);

   private:
    double height;
};

#endif
