#ifndef H_DATETYPE
#define H_DATETYPE

class dateType {
   public:
    // Function to set the date.
    // Postcondition: year = y; month = m; day = d;
    void setDate(int y, int m, int d);

    // Function to get the year.
    // Postcondition: returns the value of year.
    int getYear() const;

    // Function to get the month.
    // Postcondition: Returns the value of month.
    int getMonth() const;

    // Function to get the day.
    // Postcondition: Returns the value of day.
    int getDay() const;

    // Function to display the date.
    void printDate() const;

    // Constructor to set the date.
    // The member variables year, month, and day are set according to the
    // parameters. Postcondition: year = y; month = m; day = d. If no value are
    //     specified, the default values are used to initialize the member
    //     variables.
    dateType(int y = 1900, int m = 1, int d = 1);

   private:
    int year;
    int month;
    int day;
};

#endif
