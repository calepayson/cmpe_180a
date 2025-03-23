#include <iostream>
#include <string>
#include <vector>

#include "mergeStrings.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> test_case_1;
    test_case_1.push_back("abc");
    test_case_1.push_back("def");

    vector<string> test_case_2 = test_case_1;
    test_case_2.push_back("ghi");

    cout << test_case_1.at(0) << ", " << test_case_1.at(1) << " -> "
         << mergeStrings(test_case_1) << endl;
    cout << test_case_2.at(0) << ", " << test_case_2.at(1) << ", "
         << test_case_2.at(2) << " -> " << mergeStrings(test_case_2) << endl;

    return 0;
}
