#include <iostream>
#include <vector>

#include "mergeSortedVectors.h"

using std::cout;
using std::endl;
using std::vector;

template <class T>
void mergeVectors(const vector<T> &a, const vector<T> &b);

int main() {
    // Test 1
    vector<int> int_a = {1, 2, 3, 4, 5};
    vector<int> int_b = {2, 4, 6, 8, 10};
    mergeVectors(int_a, int_b);
    cout << endl;

    // Test 2
    vector<char> char_a = {'a', 'b', 'c'};
    vector<char> char_b = {'d', 'e', 'f'};
    mergeVectors(char_a, char_b);
    cout << endl;

    // Test 3
    vector<double> double_a = {2.0, 4.0, 6.0, 8.0, 10.0};
    vector<double> double_b = {1.0, 2.0, 3.0, 4.0, 5.0};
    mergeVectors(double_a, double_b);
    cout << endl;

    return 0;
}

template <class T>
void mergeVectors(const vector<T> &a, const vector<T> &b) {
    cout << "Vector 1: {";
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << ", ";
    }
    cout << '}' << endl;

    cout << "Vector 2: {";
    for (auto it = b.begin(); it != b.end(); it++) {
        cout << *it << ", ";
    }
    cout << '}' << endl;

    vector<T> result;
    mergeSortedVectors(a, b, result);
    cout << "Merged:   {";
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << ", ";
    }
    cout << '}' << endl;
}
