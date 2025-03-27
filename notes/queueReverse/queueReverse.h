#ifndef QUEUEREVERSE_H
#define QUEUEREVERSE_H

#include <queue>

using std::queue;

template <class T>
queue<T> &queueReverse(queue<T> &q);

template <class T>
queue<T> &queueReverse(queue<T> &q) {
    if (q.empty()) {
        return q;
    }

    T front = q.front();
    q.pop();

    queueReverse(q);

    q.push(front);

    return q;
}

#endif
