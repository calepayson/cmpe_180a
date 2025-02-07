// Illustrates output formatting instructions
// Reads all the numbers in the file raw.txt and write the numbers
// to the screen and to the file neat.txt in a neatly formatted way.

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Precondition: The streams messy_file and neat_file have been connected
// to files using the function open.
// Postcondition: The numbers in the file connected to messy_file have been
// written to the screen and to the file connected to the stream neat_file.
void make_neat(ifstream &messy_file, ofstream &neatfile,
               int number_after_decimal_point, int field_width);

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("raw.txt");
    if (fin.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    fout.open("neat.txt");
    if (fout.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    make_neat(fin, fout, 5, 12);

    fin.close();
    fout.close();

    cout << "End of program.\n";

    return 0;
}

// Uses iostream, fstream, and iomanip
void make_neat(ifstream &messy_file, ofstream &neat_file,
               int number_after_decimal_point, int field_width) {
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(number_after_decimal_point);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number_after_decimal_point);

    double next;
    while (messy_file >> next) {
        cout << setw(field_width) << next << endl;
        neat_file << setw(field_width) << next << endl;
    }
}
