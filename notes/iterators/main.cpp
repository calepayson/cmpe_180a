#include <iostream>
#include <string>
#include <vector>

int main() {
    using std::cout;
    using std::string;
    using std::vector;

    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    vector<string>::iterator it;

    for (it = cars.begin(); it != cars.end(); ++it) {
        cout << *it << "\n";
    }

    return 0;
}
