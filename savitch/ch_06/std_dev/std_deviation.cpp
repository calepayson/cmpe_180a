#include <cmath>

#include "std_deviation.h"

double std_deviation(istream &fin, double average) {
    using std::cerr;
    using std::sqrt;
    double sum;
    int count = 0;

    double next;
    while (fin >> next) {
        sum += (next - average) * (next - average);
        count++;
    }

    if (count <= 0) {
        cerr << "ERROR: std_deviation() calculated a count <= 0\n";
        exit(1);
    }

    return sqrt(sum / count);
}
