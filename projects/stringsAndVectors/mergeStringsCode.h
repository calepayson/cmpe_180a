/******************
 * mergeStrings.h *
 ******************/

#ifndef MERGESTRINGS_H
#define MERGESTRINGS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

// Merges a vector of strings.
// Precondition: All strings are of equal size.
// Postcondition: Returns a string of each character of the provided strings.
//     The format is {s1[0], s2[0], ..., sn[0], s1[1], ..., sn[m]}
//     Returns "" if the vector was empty;
//     Returns "" if strings are different sizes.
string mergeStrings(const vector<string> &a);

/*******************
 * mergeStrings.cc *
 *******************/

#include <iostream>

using std::cerr;

string mergeStrings(const vector<string> &a) {
    if (a.size() == 0) {
        return "";
    }

    string result;
    int vec_size = a.size();
    int str_size = a[0].size();

    for (int sptr = 0; sptr < str_size; sptr++) {
        for (int vptr = 0; vptr < vec_size; vptr++) {
            if (a[vptr].size() != str_size) {
                cerr << "All strings must be of equal size.";
                return "";
            }
            result = result + a[vptr][sptr];
        }
    }

    return result;
}

#endif
