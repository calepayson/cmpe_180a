#ifndef MERGESORTEDVECTORS_H
#define MERGESORTEDVECTORS_H

#include <vector>

using std::vector;

// Function to merge two sorted vectors into a single sorted vector.
// Postcondition: result will be cleared and filled with the sorted contents of
//     a and b.
template <class T>
vector<T> &mergeSortedVectors(const vector<T> &a, const vector<T> &b,
                              vector<T> &result);

template <class T>
vector<T> &mergeSortedVectors(const vector<T> &a, const vector<T> &b,
                              vector<T> &result) {
    result.clear();
    result.resize(a.size() + b.size());

    auto it_a = a.begin();
    auto it_b = b.begin();
    auto it_r = result.begin();

    while (it_a != a.end() || it_b != b.end()) {
        if (it_a != a.end() && it_b != b.end()) {
            if (*it_a <= *it_b) {
                *it_r++ = *it_a++;
            } else {
                *it_r++ = *it_b++;
            }
        } else if (it_a == a.end()) {
            *it_r++ = *it_b++;
        } else {
            *it_r++ = *it_a++;
        }
    }

    return result;
}

#endif
