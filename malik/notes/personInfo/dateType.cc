#include <iostream>

#include "dateType.h"

using std::cout;

void dateType::setDate(int y, int m, int d) {
    year = (y >= 1900) ? y : 1900;
    month = (1 <= m && m <= 12) ? m : 1;
    day = (1 <= d && d <= 31) ? d : 1;
}

int dateType::getYear() const { return year; }
int dateType::getMonth() const { return month; }
int dateType::getDay() const { return day; }

void dateType::printDate() const {
    cout << year << '-';
    if (month < 10) cout << '0';
    cout << month;
    if (day < 10) cout << '0';
    cout << day;
}

dateType::dateType(int y, int m, int d) { setDate(y, m, d); }
