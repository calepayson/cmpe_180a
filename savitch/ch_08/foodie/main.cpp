// Demonstrates the standard class string.

#include <iostream>  // Needed for cin, cout, and endl.
#include <ostream>
#include <string>  // Needed for string.

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string phrase;
    string adjective("fried"), noun("ants");
    string wish = "Bon appetit!";

    phrase = "I love " + adjective + " " + noun + "!";
    cout << phrase << endl << wish << endl;

    return 0;
}
