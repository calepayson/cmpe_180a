#include <iostream>

using std::cout;
using std::endl;

int largest(const int list[], int lowerIndex, int upperIndex);

int main() {
    int intArray[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};

    cout << "The largest element in intArray: " << largest(intArray, 0, 9)
         << endl;

    return 0;
}

int largest(const int list[], int lowerIndex, int upperIndex) {
    if (lowerIndex == upperIndex) {
        return list[lowerIndex];
    }

    int i = list[lowerIndex];
    int j = largest(list, lowerIndex + 1, upperIndex);
    if (i >= j) {
        return i;
    } else {
        return j;
    }
}
