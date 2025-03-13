#include <iostream>

#include "dayType.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

void dayType::set_day(string day) {
    if (!valid_input(day)) {
        return;
    }

    if (day == day_vector[0]) {
        day_index = 0;
    } else if (day == day_vector[1]) {
        day_index = 1;
    } else if (day == day_vector[2]) {
        day_index = 2;
    } else if (day == day_vector[3]) {
        day_index = 3;
    } else if (day == day_vector[4]) {
        day_index = 4;
    } else if (day == day_vector[5]) {
        day_index = 5;
    } else if (day == day_vector[6]) {
        day_index = 6;
    }
}

void dayType::set_day(int day) {
    if (!valid_input(day)) {
        return;
    }

    day_index = day;
}

void dayType::print() const { cout << day_vector[day_index] << endl; }

string dayType::get_today() const { return day_vector[day_index]; }

string dayType::get_yesterday() const { return day_vector[day_index - 1]; }

string dayType::get_n_days(int days) const {
    int new_index = static_cast<size_t>(day_index + days) % day_vector.size();
    return day_vector[new_index];
}

dayType::dayType() : day_index(0) {}

dayType::dayType(string day) {
    if (!valid_input(day)) {
        return;
    }

    if (day == day_vector[0]) {
        day_index = 0;
    } else if (day == day_vector[1]) {
        day_index = 1;
    } else if (day == day_vector[2]) {
        day_index = 2;
    } else if (day == day_vector[3]) {
        day_index = 3;
    } else if (day == day_vector[4]) {
        day_index = 4;
    } else if (day == day_vector[5]) {
        day_index = 5;
    } else if (day == day_vector[6]) {
        day_index = 6;
    }
}

dayType::dayType(int day) {
    if (!valid_input(day)) {
        return;
    }

    day_index = day;
}

bool dayType::valid_input(string day) const {
    for (size_t i = 0; i < day_vector.size(); i++) {
        if (day == day_vector[i]) {
            return true;
        }
    }
    cerr << "Invalid input to dayType: " << day << endl;
    return false;
}

bool dayType::valid_input(int day) const {
    if (day < 0 || day >= static_cast<int>(day_vector.size())) {
        return false;
    }
    cerr << "Invalid input to dayType: " << day << endl;
    return true;
}
