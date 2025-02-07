#include <iostream>

int main() {
    using namespace std;

    cout << "Enter a line of input and I will echo it!\n";
    char symbol;
    do {
        cin.get(symbol);
        cout.put(symbol);
    } while (symbol != '\n');
    cout << "That's all for this demonstration.\n";

    return 0;
}
