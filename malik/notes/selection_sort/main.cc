#include <iostream>

using std::cout;
using std::endl;

void selection_sort(int arr[], int size);
void print_arr(int arr[], int size);

int main() {
    int test_1[] = {12, 54, 23, 6, 525, 43, 72, 26, 67, 24};
    int test_2[] = {54, 56, 234, 76, 87, 35, 8, 53, 56, 11};

    selection_sort(test_1, 10);
    selection_sort(test_2, 10);

    print_arr(test_1, 10);
    cout << endl;
    print_arr(test_2, 10);
    cout << endl;

    return 0;
}

void selection_sort(int arr[], int size) {
    int max = 0;
    int last = size - 1;

    while (last >= 0) {
        for (int i = 0; i <= last; i++) {
            if (arr[i] > arr[max]) max = i;
        }
        int temp = arr[last];
        arr[last] = arr[max];
        arr[max] = temp;
        max = 0;
        last--;
    }
}

void print_arr(int arr[], int size) {
    cout << '(';
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << ')';
}
