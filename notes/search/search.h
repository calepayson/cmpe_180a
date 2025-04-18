#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>

// Sequential Search
int sequential_search(const int arr[], size_t size, int item) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == item) return static_cast<int>(i);
    }
    return -1;
}

// Binary Search
int binary_search(const int arr[], size_t size, int item) {
    size_t first = 0;
    size_t last = size - 1;
    size_t mid;

    while (first <= last) {
        mid = (first + last) / 2;
        if (0 > mid || mid > size) return -1;

        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
            first = mid + 1;
        else
            last = mid - 1;
    }

    return -1;
}

#endif
