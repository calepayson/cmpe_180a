#include <iostream>
#include <string>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string first_name, last_name;
    char proceed;

    do {
        cout << "Enter your first and last name:\n";
        cin >> first_name >> last_name;

        cout << "Your initials are: " << first_name[0] << ". " << last_name[0]
             << ".\n";

        cout << "Proceed? (y/n): ";
        cin >> proceed;
    } while (proceed == 'y' || proceed == 'Y');

    return 0;
}
