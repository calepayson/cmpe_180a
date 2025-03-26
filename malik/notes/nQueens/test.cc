#include <iostream>

#include "nQueensPuzzle.h"

using std::cout;
using std::endl;

int main() {
    nQueensPuzzle n4(4);
    nQueensPuzzle n8;

    cout << "Four queens: " << endl;
    n4.queensConfiguration(0);
    cout << endl;

    cout << "Eight queens: " << endl;
    n8.queensConfiguration(0);
    cout << endl;

    return 0;
}
