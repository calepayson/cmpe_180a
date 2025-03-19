#include <iostream>

#include "extClockType.h"

void extClockType::setTime(int hours, int minutes, int seconds, int zone) {
    clockType::setTime(hours, minutes, seconds);
    timeZone = (-11 <= zone && zone <= 14) ? zone : 0;
}

void extClockType::getTime(int &hours, int &minutes, int &seconds,
                           int &zone) const {
    clockType::getTime(hours, minutes, seconds);
    zone = timeZone;
}

void extClockType::printTime() const {
    clockType::printTime();
    std::cout << '+' << timeZone;
}

bool extClockType::equalTime(const extClockType &otherClock) const {
    int this_hr, this_min, this_sec, other_hr, other_min, other_sec;
    clockType::getTime(this_hr, this_min, this_sec);
    otherClock.clockType::getTime(other_hr, other_min, other_sec);

    return ((this_hr + timeZone) == (other_hr + otherClock.timeZone) &&
            (this_min == other_min) && (this_sec == other_sec));
}

extClockType::extClockType(int hours, int minutes, int seconds, int zone) {
    clockType(hours, minutes, seconds);
    timeZone = (-11 <= zone && zone <= 14) ? zone : 0;
}

extClockType::extClockType() {
    clockType();
    timeZone = 0;
}
