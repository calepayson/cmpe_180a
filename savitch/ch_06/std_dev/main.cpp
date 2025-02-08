#include <cmath>
#include <fstream>
#include <iostream>

using std::istream;

double average(istream &fin);

double std_deviation(istream &fin, double average);

int main() {
    using std::cerr;
    using std::cout;
    using std::ifstream;

    double avg, std_dev;
    ifstream fin;

    fin.open("data.txt");
    if (fin.fail()) {
        cerr << "Error: Failed to open data.txt\n";
        exit(1);
    }
    avg = average(fin);
    fin.close();

    fin.open("data.txt");
    if (fin.fail()) {
        cerr << "Error: Failed to open data.txt\n";
        exit(1);
    }
    std_dev = std_deviation(fin, avg);
    fin.close();

    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);
    cout.precision(2);

    cout << "Average: " << avg << '\n';
    cout << "Std dev: " << std_dev << '\n';

    return 0;
}
