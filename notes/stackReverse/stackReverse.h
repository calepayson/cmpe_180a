#ifndef STACKREVERSE_H
#define STACKREVERSE_H

#include <stack>

using std::stack;

template <class T>
stack<T> &insertAtBottom(stack<T> &s, const T &top);

template <class T>
stack<T> &stackReverse(stack<T> &s);

template <class T>
stack<T> &insertAtBottom(stack<T> &s, const T &top) {
    if (s.empty()) {
        s.push(top);
        return s;
    }

    T topItem = s.top();
    s.pop();

    insertAtBottom(s, top);

    s.push(topItem);

    return s;
}

template <class T>
stack<T> &stackReverse(stack<T> &s) {
    if (s.empty()) {
        return s;
    }

    T top = s.top();
    s.pop();

    stackReverse(s);

    insertAtBottom(s, top);

    return s;
}

#endif
