//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// This program illustrates how to use the function copy and an ostream iterator
// in a program.
//*****************************************************************************

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
    int intArray[] = {5, 6, 8, 3, 40, 36, 98, 29, 75};

    vector<int> vecList(9);

    ostream_iterator<int> screen(cout, ", ");

    cout << "intArray: ";
    copy(intArray, intArray + 9, screen);
    cout << endl;

    copy(intArray, intArray + 9, vecList.begin());
    cout << "vecList: ";
    copy(vecList.begin(), vecList.end(), screen);
    cout << endl;

    copy(intArray + 1, intArray + 9, intArray);
    cout << "After shifting elements one position to the left," << endl;
    cout << "intArray: ";
    copy(intArray, intArray + 9, screen);
    cout << endl;

    copy(vecList.rbegin(), vecList.rend(), vecList.begin());
    cout << "After reversing," << endl;
    cout << "vecList: ";
    copy(vecList.begin(), vecList.end(), screen);
    cout << endl;

    return 0;
}
