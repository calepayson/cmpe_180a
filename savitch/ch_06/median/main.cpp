#include <fstream>
#include <iostream>

using std::ifstream;
using std::istream;

ifstream open_data();

int nums_in_file(istream &fin);

double get_median(istream &fin, int start, int stop);

int main() {
    using std::cout;

    double first_quartile, median, third_quartile;
    int count;
    ifstream fin;

    fin = open_data();
    count = nums_in_file(fin);
    fin.close();

    fin = open_data();
    median = get_median(fin, 0, count);
    fin.close();

    fin = open_data();
    first_quartile = get_median(fin, 0, count / 2);
    fin.close();

    fin = open_data();
    third_quartile = get_median(fin, count / 2, count);
    fin.close();

    cout << "First quartile: " << first_quartile << '\n';
    cout << "Median:         " << median << '\n';
    cout << "Third quartile: " << third_quartile << '\n';

    return 0;
}

ifstream open_data() {
    using std::cerr;

    ifstream fin;

    fin.open("data.txt");
    if (fin.fail()) {
        cerr << "Unknown file: data.txt\n";
        exit(1);
    }

    return fin;
}

int nums_in_file(istream &fin) {
    int next, count;

    count = 0;
    while (fin >> next) {
        count++;
    }

    return count;
}

double get_median(istream &fin, int start, int stop) {
    using std::cerr;
    int count;
    double current;

    count = stop - start;

    if (count <= 0) {
        cerr << "Error: Input range is zero or negative.\n";
        exit(1);
    }

    if (count % 2 == 1) {
        count++;

        // Get to start of range
        for (int i = 0; i < start; i++) {
            fin >> current;
        }

        // Grab the median
        int offset = 0;
        for (; offset < count / 2; ++offset) {
            fin >> current;
        }
    } else {
        // Get to start of range
        for (int i = 0; i < start; i++) {
            fin >> current;
        }

        // Grab the median
        int offset = 0;
        for (; offset < count / 2; ++offset) {
            fin >> current;
        }

        // Take the average of two items if the median falls between them
        if (count % 2 == 0) {
            double next;
            fin >> next;
            current = (current + next) / 2;
        }
    }

    return current;
}
