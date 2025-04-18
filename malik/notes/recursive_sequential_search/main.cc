#include <iostream>

using std::cout;
using std::endl;

int sequential_search(int arr[], int start, int end, int target);

int main() {
    int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "arr: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << endl;
    cout << "search(0): " << sequential_search(test, 0, 9, 0) << endl;
    cout << "search(9): " << sequential_search(test, 0, 9, 9) << endl;
    cout << "search(5): " << sequential_search(test, 0, 9, 5) << endl;
    cout << "search(-1): " << sequential_search(test, 0, 9, -1) << endl;
    cout << "search(10): " << sequential_search(test, 0, 9, 10) << endl;

    return 0;
}

int sequential_search(int arr[], int start, int end, int target) {
    if (start > end) return -1;
    if (arr[start] == target) return start;
    return sequential_search(arr, ++start, end, target);
}
