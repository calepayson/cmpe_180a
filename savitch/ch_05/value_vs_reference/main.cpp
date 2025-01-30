// Illustrates the difference between a call-by-value parameter and
// a call-by-reference parameter.

#include <iostream>

// par1_value is a call-by-value formal parameter and par2_reference
// is a call-by-reference formal parameter.
void do_stuff(int par1_value, int &par2_reference);

int main() {
    using namespace std;
    int n1, n2;

    n1 = 1;
    n2 = 2;
    do_stuff(n1, n2);
    cout << "n1 after function call = " << n1 << endl;
    cout << "n2 after function call = " << n2 << endl;

    return 0;
}

void do_stuff(int par1_value, int &par2_reference) {
    using namespace std;

    par1_value = 111;
    cout << "par1_value in function call = " << par1_value << endl;

    par2_reference = 222;
    cout << "par2_reference in function call = " << par2_reference << endl;
}
