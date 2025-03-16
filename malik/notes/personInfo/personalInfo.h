#ifndef H_PERSONALINFO
#define H_PERSONALINFO

#include "dateType.h"
#include "personType.h"

class personalInfo {
   public:
    // Function to set the personal information.
    // The member variables are set according to the parameters.
    // Postcondition: firstName = first; lastName = last; year = y; month = m;
    //     day = d; personID = ID;
    void setPersonalInfo(string first, string last, int y, int m, int d,
                         int ID);

    // Function to print the personal information.
    void printPersonalInfo() const;

    // Constructor
    // The member variables are set according to the parameters.
    // Postcondition: firstName = first; lastName = last; year = y; month = m;
    //     day = d; personID = ID;
    //     If no values are specified, the default values are used to initialize
    //     the member variables.
    personalInfo(string first, string last, int y, int m, int d, int ID);

   private:
    personType name;
    dateType bDay;
    int personID;
};

#endif
