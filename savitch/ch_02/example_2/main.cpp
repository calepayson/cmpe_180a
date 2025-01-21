#include <iostream>

using namespace std;

int main() {
    char symbol_1, symbol_2, symbol_3;

    cout << "Enter two initials, without any periods:\n";
    cin >> symbol_1 >> symbol_2;
    cout << "The two initials are:\n";
    cout << symbol_1 << symbol_2 << endl;
    symbol_3 = ' ';
    cout << symbol_1 << symbol_3 << symbol_2 << endl;
    cout << "That's all folks.\n";

    return 0;
}
