#include <iostream>

#include "complexNumber.h"

using std::istream;
using std::ostream;

ostream &operator<<(ostream &out, const complexType &complex) {
    out << '(' << complex.realPart << ", " << complex.imaginaryPart << ")";
    return out;
}

istream &operator>>(istream &in, complexType &complex) {
    char ch;

    in >> ch >> complex.realPart >> ch >> complex.imaginaryPart >> ch;

    return in;
}

void complexType::setComplex(const double &real, const double &imag) {
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double &real, double &imag) const {
    real = realPart;
    imag = imaginaryPart;
}

complexType::complexType(double real, double imag)
    : realPart(real), imaginaryPart(imag) {}

complexType complexType::operator+(const complexType &otherComplex) const {
    complexType tempComplex;

    tempComplex.realPart = realPart + otherComplex.realPart;
    tempComplex.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

    return tempComplex;
}

complexType complexType::operator*(const complexType &otherComplex) const {
    complexType tempComplex;

    tempComplex.realPart = (realPart * otherComplex.realPart) -
                           (imaginaryPart * otherComplex.imaginaryPart);

    tempComplex.imaginaryPart = (realPart * otherComplex.imaginaryPart) -
                                (imaginaryPart + otherComplex.realPart);

    return tempComplex;
}

bool complexType::operator==(const complexType &otherComplex) const {
    return (realPart == otherComplex.realPart &&
            imaginaryPart == otherComplex.imaginaryPart);
}
