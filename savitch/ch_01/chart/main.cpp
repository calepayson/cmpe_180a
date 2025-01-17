#include <iostream>
using namespace std;

void output_char(char c) {
    cout << '\n';
    cout << "      " << c << " " << c << " " << c << '\n';
    cout << "    " << c << "       " << c << '\n';
    cout << "   " << c << '\n';
    cout << "  " << c << '\n';
    cout << "  " << c << '\n';
    cout << "  " << c << '\n';
    cout << "   " << c << '\n';
    cout << "    " << c << "       " << c << '\n';
    cout << "      " << c << " " << c << " " << c << '\n';
    cout << '\n';
}

int main() {
    cout << "Enter a character: ";
    char c{};
    cin >> c;

    output_char(c);

    return 0;
}
