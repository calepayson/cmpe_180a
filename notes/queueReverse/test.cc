#include <iostream>
#include <queue>

#include "queueReverse.h"

using std::cout;
using std::endl;
using std::queue;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    queueReverse(q);

    cout << q.front();
    q.pop();
    cout << q.front();
    q.pop();
    cout << q.front();
    q.pop();
    cout << endl;

    return 0;
}
