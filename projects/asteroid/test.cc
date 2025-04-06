#include <iostream>
#include <vector>

#include "asteroid.h"
#include "countHits.h"

using std::cout;
using std::endl;
using std::vector;

void test_count_hits(const vector<Asteroid> &a, int hits);
void print_asteroids(const vector<Asteroid> &a);
void print_asteroid(const Asteroid &a);

int main() {
    vector<Asteroid> test1 = {{10, right}, {11, left}, {11, right}, {5, left}};
    test_count_hits(test1, 1);
    cout << "--------------------------------------" << endl;

    vector<Asteroid> test2 = {{10, right}, {11, right}, {11, right}};
    test_count_hits(test2, 3);
    cout << "--------------------------------------" << endl;

    vector<Asteroid> test3 = {{1, right}, {1, left}, {1, right}, {1, left}};
    test_count_hits(test3, 0);
    cout << "--------------------------------------" << endl;

    vector<Asteroid> test4 = {{5, right}, {1, right}, {3, right}, {8, left}};
    test_count_hits(test4, 0);
    cout << "--------------------------------------" << endl;

    return 0;
}

void test_count_hits(const vector<Asteroid> &a, int hits) {
    print_asteroids(a);
    cout << endl;
    cout << "Expect " << hits << " hit" << ((hits > 1) ? "s" : "") << endl;
    cout << "Got " << countHits(a) << endl;
}

void print_asteroids(const vector<Asteroid> &a) {
    for (int i = 0; i < a.size(); ++i) {
        print_asteroid(a[i]);
        if (i != a.size() - 1) {
            cout << ", ";
        }
    }
}

void print_asteroid(const Asteroid &a) {
    cout << '{' << a.m << ", " << ((a.d == left) ? "left" : "right") << '}';
}
