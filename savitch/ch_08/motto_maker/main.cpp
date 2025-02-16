// Demonstrates getline and cin.get

#include <iostream>  // cout, cin, endl
#include <string>    // string, getline()

void new_line();

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::getline;
    using std::string;

    string first_name, last_name, record_name;
    string motto = "Your records are our records.";
    cout << "Enter your first and last name:\n";
    cin >> first_name >> last_name;

    new_line();
    record_name = last_name + ", " + first_name;

    cout << "Your name in our records is: ";
    cout << record_name << endl;
    cout << "Our motto is\n" << motto << endl;
    cout << "Please suggest a better (one-line) motto:\n";

    getline(cin, motto);

    cout << "Our new motto will be:\n";
    cout << motto << endl;

    return 0;
}

// Uses iostream:
void new_line() {
    using std::cin;

    char next_char;

    do {
        cin.get(next_char);
    } while (next_char != '\n');
}
