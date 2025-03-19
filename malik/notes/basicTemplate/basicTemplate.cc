#include <iostream>
#include <string>

using namespace std;

template <class Type>
Type larger(Type x, Type y);

int main() {
    cout << "Line 10: Larger of 5 and 6 = " << larger(5, 6) << endl;
    cout << "Line 11: Larger of A and B = " << larger('A', 'B') << endl;
    cout << "line 12: Larger of 5.6 and 3.2 = " << larger(5.6, 3.2) << endl;
    string str1 = "Hello";
    string str2 = "Happy";
    cout << "Line 15: Larger of " << str1 << " and " << str2 << " = "
         << larger(str1, str2) << endl;

    return 0;
}

template <class Type>
Type larger(Type x, Type y) {
    return (x >= y) ? x : y;
}
