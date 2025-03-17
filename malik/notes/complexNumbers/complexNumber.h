#ifndef H_complexNumber
#define H_complexNumber

//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
// class complexType.h
// This class specifies the members to implement a complex number.
//*****************************************************************************

#include <iostream>

using std::istream;
using std::ostream;

class complexType {
    // Overload the stream insertion and extraction operators
    friend ostream &operator<<(ostream &, const complexType &);
    friend istream &operator>>(istream &, complexType &);

   public:
    // Function to set the complex numbers according to the parameters.
    // Postcondition realPart = real; imaginaryPart = imag;
    void setComplex(const double &real, const double &imag);

    // Function to retrieve the complex number.
    // Postcondition real = realPart; imag = imaginaryPart;
    void getComplex(double &real, double &imag) const;

    // Constructor
    // Initializes the complex number according to the parameters.
    // Postcondition: realPart = real; imaginaryPart = imag;
    complexType(double real = 0, double imag = 0);

    // Overload the operator +
    complexType operator+(const complexType &otherComplex) const;

    // Overload the operator *
    complexType operator*(const complexType &otherComplex) const;

    // Overload the operator ==
    bool operator==(const complexType &otherComplex) const;

   private:
    double realPart;       // Variable to store the real part.
    double imaginaryPart;  // Variable to store the imaginary part.
};

#endif
