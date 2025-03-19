#ifndef EXTCLOCKTYPE_H
#define EXTCLOCKTYPE_H

#include "clockType.h"

class extClockType : public clockType {
   public:
    // Function to set the time.
    // The time is set according to the parameters.
    // Postcondition: hr = hours; min = minutes; sec = seconds; timeZone = zone;
    //     The function checks whether the values of hours, minutes, seconds,
    //     and zone are valid. If a value is invalid, the default value 0 is
    //     assigned.
    void setTime(int hours, int minutes, int seconds, int zone);

    // Function to get the time.
    // Postcondition: hours = hr; minutes = min; seconds = sec; zone = timeZone;
    void getTime(int &hours, int &minutes, int &seconds, int &zone) const;

    // Function to print the time.
    // Postcondition: Time is printed in the form hh::mm::ss+timeZone;
    void printTime() const;

    // Function to check if two times are equal.
    // Postcondition: Return true if this time is equal to otherClock.
    //     Otherwise, returns false.
    bool equalTime(const extClockType &otherClock) const;

    // Constructor with Parameters.
    // The time is set according to the parameters.
    // Postcondition: hr = hours; min = minutes; sec = seconds; timeZone = zone;
    //     The constructor checks whether the values of hours, minutes, seconds,
    //     and zone are valid. If a value is invalid, the default value 0 is
    //     assigned.
    extClockType(int hours, int minutes, int seconds, int zone);

    // Default constructor.
    // Postcondition: hr = 0; min = 0; sec = 0; timeZone = 0;
    extClockType();

   private:
    int timeZone;  // Stores the time-zone
};

#endif
