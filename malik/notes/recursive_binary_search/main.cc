#include <iostream>

using std::cout;
using std::endl;

int binary_search(int arr[], int start, int end, int target);

int main() {
    int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "arr: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}" << endl;
    cout << "search(0): " << binary_search(test, 0, 9, 0) << endl;
    cout << "search(9): " << binary_search(test, 0, 9, 9) << endl;
    cout << "search(5): " << binary_search(test, 0, 9, 5) << endl;
    cout << "search(-1): " << binary_search(test, 0, 9, -1) << endl;
    cout << "search(10): " << binary_search(test, 0, 9, 10) << endl;

    return 0;
}

int binary_search(int arr[], int start, int end, int target) {
    if (start > end) return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search(arr, mid + 1, end, target);
    } else {
        return binary_search(arr, start, mid - 1, target);
    }
}
