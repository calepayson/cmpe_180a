#include <iostream>

using std::cout;
using std::endl;

template <class T>
struct llNode {
    T data;
    llNode *next;
};

template <class T>
void print_ll(llNode<T> *root);

template <class T>
llNode<T> *build_ll(T arr[], size_t size);

template <class T>
void insertion_sort(llNode<T> *&head);

int main() {
    int arr[] = {34, 756, 34, 45, 453, 345, 45, 67, 87, 3, 7812, 68, 73};
    llNode<int> *test_1 = build_ll(arr, 10);
    print_ll(test_1);
    cout << endl;

    insertion_sort(test_1);
    print_ll(test_1);
    cout << endl;

    return 0;
}

template <class T>
void print_ll(llNode<T> *root) {
    cout << '(';
    while (root != NULL) {
        cout << root->data;
        if (root->next != NULL) cout << ", ";
        root = root->next;
    }
    cout << ')';
}

template <class T>
llNode<T> *build_ll(T arr[], size_t size) {
    if (size <= 0) return NULL;

    llNode<T> *start = new llNode<T>;
    start->data = arr[0];
    start->next = NULL;

    llNode<T> *end = start;

    for (size_t i = 1; i < size; i++) {
        llNode<T> *temp = new llNode<T>;
        temp->data = arr[i];
        temp->next = NULL;

        end->next = temp;
        end = temp;
    }

    return start;
}

template <class T>
void insertion_sort(llNode<T> *&head) {
    if (head == NULL) return;

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        llNode<T> *current = head;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                sorted = false;
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }
}
