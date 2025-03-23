#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <cassert>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

template <class elemType>
class arrayListType {
   public:
    const arrayListType<elemType> &operator=(const arrayListType<elemType> &);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType &item) const;
    void insertAt(int location, const elemType &insertItem);
    void insertEnd(const elemType &insertItem);
    void removeAt(int location);
    void retrieveAt(int location, elemType &retItem) const;
    void replaceAt(int location, const elemType &repItem);
    void clearList();
    int seqSearch(const elemType &item) const;
    void insert(const elemType &insertItem);
    void remove(const elemType &removeItem);

    arrayListType(int size = 100);
    arrayListType(const arrayListType<elemType> &otherList);
    ~arrayListType();

   protected:
    elemType *list;  // Array to hold the list elements
    int length;      // To store the length of the list
    int maxSize;     // To store the maxSize of the list
};

template <class elemType>
const arrayListType<elemType> &arrayListType<elemType>::operator=(
    const arrayListType<elemType> &otherList) {
    if (this != &otherList) {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[length];
        assert(list != NULL);

        for (int i = 0; i < length; i++) {
            list[i] = otherList.list[i];
        }
    }

    return *this;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const {
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const {
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const {
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const {
    cout << '[';
    for (int i = 0; i < length; i++) {
        cout << list[i];
        if (i != length - 1) cout << ", ";
    }
    cout << ']';
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location,
                                            const elemType &item) const {
    return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location,
                                       const elemType &insertItem) {
    if (location < 0 || location >= maxSize) {
        cerr << "The position of the item to be inserted is out of range."
             << endl;
        return;
    }
    if (length >= maxSize) {
        cerr << "Cannot insert in a full list" << endl;
        return;
    }

    for (int i = length; i > location; i--) {
        list[i] = list[i - 1];
    }
    list[location] = insertItem;
    length++;
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem) {
    if (length >= maxSize) {
        cerr << "Cannot insert in a full list" << endl;
        return;
    }

    list[length++] = insertItem;
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if (location < 0 || location >= length) {
        cerr << "the position of the item to be inserted is out of range"
             << endl;
        return;
    }

    for (int i = location; i < length - 1; i++) {
        list[i] = list[i + 1];
    }
    length--;
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location,
                                         elemType &retItem) const {
    if (location < 0 || location >= length) {
        cerr << "the position of the item to be inserted is out of range"
             << endl;
        return;
    }

    retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType &repItem) {
    if (location < 0 || location >= length) {
        cerr << "the position of the item to be inserted is out of range"
             << endl;
        return;
    }

    list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList() {
    length = 0;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType &item) const {
    for (int i = 0; i < length; i++) {
        if (list[i] == item) {
            return i;
        }
    }
    return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType &insertItem) {
    if (length >= maxSize) {
        cerr << "Cannot insert in a full list" << endl;
        return;
    }

    list[length++] = insertItem;
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType &removeItem) {
    if (length == 0) {
        cerr << "Cannot delete from an empty list" << endl;
    }

    for (int i = 0; i < length; i++) {
        if (list[i] == removeItem) {
            removeAt(i);
            return;
        }
    }

    cerr << "removeItem not found" << endl;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    if (size < 0) {
        cerr
            << "The array size must be positive. Creating an array of size 100."
            << endl;
        maxSize = 100;
    } else {
        maxSize = size;
    }

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::arrayListType(
    const arrayListType<elemType> &otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);

    for (int i = 0; i < length; i++) {
        list[i] = otherList.list[i];
    }
}

template <class elemType>
arrayListType<elemType>::~arrayListType() {
    delete[] list;
}

#endif
