#include <iostream>

#include "clockType.h"

using std::cout;

void clockType::setTime(int hours, int minutes, int seconds) {
    hr = (0 <= hours && hours < 24) ? hours : 0;
    min = (0 <= minutes && minutes < 60) ? minutes : 0;
    sec = (0 <= seconds && seconds < 60) ? seconds : 0;
}

void clockType::getTime(int &hours, int &minutes, int &seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const {
    if (hr < 10) cout << '0';
    cout << hr << ':';
    if (min < 10) cout << '0';
    cout << min << ':';
    if (sec < 10) cout << '0';
    cout << sec;
}

void clockType::incrementHours() {
    if (hr == 23)
        hr = 0;
    else {
        hr++;
    }
}

void clockType::incrementMinutes() {
    if (min == 59) {
        min = 0;
        incrementHours();
    } else {
        min++;
    }
}

void clockType::incrementSeconds() {
    if (sec == 59) {
        sec = 0;
        incrementMinutes();
    } else {
        min++;
    }
}

bool clockType::equalTime(const clockType &otherClock) const {
    return (hr == otherClock.hr && min == otherClock.min &&
            sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds) {
    hr = (0 <= hours && hours < 24) ? hours : 0;
    min = (0 <= minutes && minutes < 60) ? minutes : 0;
    sec = (0 <= seconds && seconds < 60) ? seconds : 0;
}

clockType::clockType() {
    hr = 0;
    min = 0;
    sec = 0;
}
