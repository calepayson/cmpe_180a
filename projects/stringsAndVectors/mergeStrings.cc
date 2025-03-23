#include <iostream>

#include "mergeStrings.h"

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
