#include <iostream>

#include "dayType.h"

int main() {
    using std::cout;
    using std::endl;

    dayType day;

    day.print();
    cout << endl;

    day.set_day("Monday");
    day.print();
    cout << endl;

    cout << "Today: " << day.get_today() << endl;
    cout << "Yesterday: " << day.get_yesterday() << endl;
    cout << endl;

    cout << "In three days: " << day.get_n_days(3) << endl;

    return 0;
}
