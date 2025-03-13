#ifndef DAYTYPE_H
#define DAYTYPE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class dayType {
   public:
    void set_day(string day);
    void set_day(int day);

    void print() const;
    string get_today() const;
    string get_yesterday() const;

    string get_n_days(int days) const;

    dayType();
    dayType(string day);
    dayType(int day);

   private:
    bool valid_input(string day) const;
    bool valid_input(int day) const;

    int day_index;
    vector<string> day_vector = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};
};

#endif
