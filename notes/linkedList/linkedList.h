#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
struct Node {
    T data;
    Node *next;
};

template <class T>
class linkedList {
   public:
    // Default constructor
    linkedList<T>();

    // Destructor
    virtual ~linkedList<T>();

    T &peek(T &data) const;
    int size() const;

    void push(T &data);
    void pop();

   private:
    Node<T> *head;
    int noNodes;
};

template <class T>
linkedList<T>::linkedList() : head(NULL), noNodes(0) {}

template <class T>
linkedList<T>::~linkedList() {
    Node<T> *current = head;
    Node<T> *temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
}

template <class T>
T &linkedList<T>::peek(T &data) const {
    data = head->data;
    return data;
}

template <class T>
int linkedList<T>::size() const {
    return noNodes;
}

template <class T>
void linkedList<T>::push(T &data) {
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    noNodes++;
}

template <class T>
void linkedList<T>::pop() {
    if (noNodes == 0) {
        std::cerr << "Unable to pop from empty list.\n";
        return;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
    noNodes--;
}

#endif
