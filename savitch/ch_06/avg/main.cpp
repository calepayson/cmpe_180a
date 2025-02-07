#include <fstream>
#include <iostream>

int main() {
    using std::cerr;
    using std::cout;
    using std::ifstream;

    double total, next;
    int count;
    ifstream fin;

    fin.open("data.txt");
    if (fin.fail()) {
        cerr << "Error opening data.txt\n";
        exit(1);
    }

    count = 0;

    while (fin >> next) {
        total = total + next;
        count++;
    }

    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);
    cout.precision(2);

    if (count > 0) {
        cout << "Average: " << total / count << '\n';
    } else {
        cout << "No doubles provided.\n";
    }

    return 0;
}
