#include "average.h"

double average(istream &fin) {
    using std::cerr;

    double total = 0;
    int count = 0;

    double next;
    while (fin >> next) {
        total += next;
        count++;
    }

    if (count <= 0) {
        cerr << "ERROR: average() calculated a count <= 0\n";
        exit(1);
    }

    return total / count;
}
