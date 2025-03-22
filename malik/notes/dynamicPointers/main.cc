#include <iostream>

using std::cout;
using std::endl;

int main() {
    int *p;
    int *q;

    p = new int;
    *p = 34;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << endl;

    q = p;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    cout << endl;

    *q = 45;
    cout << "*p = " << *p << endl;
    cout << "*q = " << *q << endl;
    cout << endl;

    p = new int;
    *p = 18;
    cout << "*p = " << *p << endl;
    cout << "*q = " << *q << endl;
    cout << endl;

    delete q;
    q = NULL;
    q = new int;
    *q = 62;
    cout << "*p = " << *p << endl;
    cout << "*q = " << *q << endl;
    cout << endl;

    delete p;
    delete q;

    return 0;
}
