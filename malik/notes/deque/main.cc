//*****************************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use a deque container in a program.
//*****************************************************************************

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

using std::cout;
using std::deque;
using std::endl;
using std::ostream_iterator;

int main() {
    deque<int> intDeq;
    ostream_iterator<int> screen(cout, " ");

    intDeq.push_back(13);
    intDeq.push_back(75);
    intDeq.push_back(28);
    intDeq.push_back(35);

    cout << "intDeq: ";
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    intDeq.push_front(0);
    intDeq.push_front(100);

    cout << "intDeq: ";
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    intDeq.pop_front();
    intDeq.pop_front();

    cout << "intDeq: ";
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    intDeq.pop_back();
    intDeq.pop_back();

    cout << "intDeq: ";
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    deque<int>::iterator deqIt;

    deqIt = intDeq.begin();
    ++deqIt;
    intDeq.insert(deqIt, 444);
    cout << "intDeq: ";
    copy(intDeq.begin(), intDeq.end(), screen);
    cout << endl;

    return 0;
}
