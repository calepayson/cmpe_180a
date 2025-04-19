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
void selection_sort(llNode<T> *&head);

int main() {
    int arr[] = {34, 756, 34, 45, 453, 345, 45, 67, 87, 3, 7812, 68, 73};
    llNode<int> *test_1 = build_ll(arr, 10);
    print_ll(test_1);
    cout << endl;

    selection_sort(test_1);
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
llNode<T> *pop_min(llNode<T> *&head) {
    if (head == NULL) return NULL;

    llNode<T> *pre_min = NULL;
    llNode<T> *min = head;

    // Find min
    llNode<T> *prev = head;
    while (prev->next != NULL) {
        if (prev->next->data < min->data) {
            pre_min = prev;
            min = prev->next;
        }
        prev = prev->next;
    }

    // Remove min from list
    if (pre_min == NULL) {
        head = min->next;
    } else {
        pre_min->next = min->next;
    }
    min->next = NULL;

    // Return min node;
    return min;
}

template <class T>
void selection_sort(llNode<T> *&head) {
    llNode<T> *temp = NULL;
    llNode<T> *temp_tail = NULL;

    while (head != NULL) {
        if (temp == NULL) {
            temp = pop_min(head);
            temp_tail = temp;
        } else {
            temp_tail->next = pop_min(head);
            temp_tail = temp_tail->next;
        }
    }

    head = temp;
}
