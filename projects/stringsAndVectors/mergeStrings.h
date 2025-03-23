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

#endif
