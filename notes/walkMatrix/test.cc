#include <iostream>
#include <vector>

#include "walkMatrix.h"

using std::cout;
using std::endl;
using std::vector;

void printMatrix(const vector<vector<int>> &matrix);
void testWalkMatrix(const vector<vector<int>> &matrix, bool walkable);

int main() {
    // Test 1
    vector<vector<int>> m1 = {{0, 0}, {1, 0}};
    testWalkMatrix(m1, true);
    cout << endl;

    // Test 2
    vector<vector<int>> m2 = {{0, 1}, {1, 0}};
    testWalkMatrix(m2, false);
    cout << endl;

    // Test 3
    vector<vector<int>> m3 = {
        {0, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}};
    testWalkMatrix(m3, true);
    cout << endl;

    // Test 3
    vector<vector<int>> m4 = {
        {0, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 1, 1}, {0, 0, 0, 1, 0, 0, 1, 0}};
    testWalkMatrix(m4, false);
    cout << endl;

    return 0;
}

void printMatrix(const vector<vector<int>> &matrix) {
    for (auto it_i = matrix.begin(); it_i != matrix.end(); it_i++) {
        for (auto it_j = it_i->begin(); it_j != it_i->end(); it_j++) {
            cout << *it_j << ' ';
        }
        cout << endl;
    }
}

void testWalkMatrix(const vector<vector<int>> &matrix, bool walkable) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);
    bool result = walkMatrix(matrix);
    cout << "Expected: " << (walkable ? "True" : "False") << endl;
    cout << "Got: " << (result ? "True" : "False") << endl;
    cout << ((result == walkable) ? "SUCCESS!" : "FAILURE!") << endl;
}
