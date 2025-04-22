#include <iostream>

#include "CircularLinkedList.h"

using std::cerr;
using std::endl;
using std::ostream;

CircularLinkedList::CircularLinkedList() : head(NULL) {}

CircularLinkedList::~CircularLinkedList() {
    if (head == NULL) return;

    llNode *current = head->next;
    while (head != NULL) {
        if (current == head) {
            delete current;
            head = NULL;
        } else {
            llNode *tmp = current;
            current = current->next;
            delete tmp;
        }
    }
}

void CircularLinkedList::push(int i, ClockDirection d) {
    llNode *new_node = new llNode;
    new_node->data = i;
    if (head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    } else if (d == ClockWise) {
        new_node->next = head->next;
        new_node->prev = head;
        head->next = new_node;
        new_node->next->prev = new_node;
    } else {
        new_node->prev = head->prev;
        new_node->next = head;
        new_node->prev->next = new_node;
        ;
        head->prev = new_node;
    }
}

int CircularLinkedList::pop(ClockDirection d) {
    // No data
    if (head == NULL) {
        cerr << "Cannot pop from an empty list!" << endl;
        return 0;
    }

    // Only one item;
    if (head->next == head) {
        int result = head->data;
        delete head;
        head = NULL;
        return result;
    }

    // Multiple items;
    int result = head->data;
    llNode *tmp = head;
    if (d == ClockWise) {
        head = head->next;
        head->prev = tmp->prev;
        head->prev->next = head;
    } else {
        head = head->prev;
        head->next = tmp->next;
        head->next->prev = head;
    }

    delete tmp;
    return result;
}

int CircularLinkedList::peek() const { return head->data; }

void CircularLinkedList::rotate(unsigned int n, ClockDirection d) {
    if (head == NULL) {
        cerr << "Cannot rotate an empty list" << endl;
        return;
    }

    while (n > 0) {
        if (d == ClockWise) {
            head = head->next;
        } else {
            head = head->prev;
        }
        --n;
    }
}

ostream &operator<<(ostream &os, const CircularLinkedList &list) {
    os << '{';
    if (list.head != NULL) {
        llNode *current = list.head;
        while (current->next != list.head) {
            os << current->data << ", ";
            current = current->next;
        }
        os << current->data;
    }
    os << '}';
    return os;
}
