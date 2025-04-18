#include <iostream>

#include "search.h"

using std::cout;
using std::endl;

void test_search(int (*fptr)(const int *, size_t, int));

int main() {
    cout << "-----------------" << endl;
    cout << "Sequential Search" << endl;
    cout << "-----------------" << endl;
    test_search(sequential_search);

    cout << endl;

    cout << "-------------" << endl;
    cout << "Binary Search" << endl;
    cout << "-------------" << endl;
    test_search(binary_search);

    return 0;
}

void test_search(int (*fptr)(const int *, size_t, int)) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    if (fptr(arr, 10, 1) == 0) {
        cout << "SUCCESS! Found at idx 1." << endl;
    } else {
        cout << "FAILURE! idx not found." << endl;
    }

    if (fptr(arr, 10, 0) == 9) {
        cout << "SUCCESS! Found at idx 9." << endl;
    } else {
        cout << "FAILURE! idx not found." << endl;
    }

    if (fptr(arr, 10, 5) == 4) {
        cout << "SUCCESS! Found at idx 4." << endl;
    } else {
        cout << "FAILURE! idx not found." << endl;
    }

    if (fptr(arr, 10, 12) == -1) {
        cout << "SUCCESS! Not found." << endl;
    } else {
        cout << "FAILURE! Found." << endl;
    }
}
