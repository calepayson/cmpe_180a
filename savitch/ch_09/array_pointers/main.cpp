#include <iostream>

typedef int *IntPtr;

int main() {
    using std::cout;
    using std::endl;

    IntPtr p;
    int a[10];
    int index;

    for (index = 0; index < 10; index++) {
        a[index] = index;
    }

    p = a;

    for (index = 0; index < 10; index++) {
        cout << p[index] << ' ';
    }
    cout << endl;

    for (index = 0; index < 10; index++) {
        p[index] = p[index] + 1;
    }

    for (index = 0; index < 10; index++) {
        cout << a[index] << ' ';
    }
    cout << endl;

    return 0;
}
