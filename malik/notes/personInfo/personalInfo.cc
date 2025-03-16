#include <iostream>

#include "personalInfo.h"

using std::cout;

void personalInfo::setPersonalInfo(string first, string last, int y, int m,
                                   int d, int ID) {
    name.setName(first, last);
    bDay.setDate(y, m, d);
    personID = ID;
}

void personalInfo::printPersonalInfo() const {
    name.print();
    cout << " ";
    bDay.printDate();
    cout << " " << personID;
}

personalInfo::personalInfo(string first, string last, int y, int m, int d,
                           int ID) {
    setPersonalInfo(first, last, y, m, d, ID);
}
