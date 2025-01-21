#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter the first or last name of your instructor: ";
    string instructor_name{};
    cin >> instructor_name;

    cout << "Enter your name: ";
    string your_name{};
    cin >> your_name;

    cout << "Enter a food: ";
    string food{};
    cin >> food;

    cout << "Enter a number between 100 and 120: ";
    double number{};
    cin >> number;

    cout << "Enter an adjective: ";
    string adjective{};
    cin >> adjective;

    cout << "Enter a color: ";
    string color{};
    cin >> color;

    cout << "Enter an animal: ";
    string animal{};
    cin >> animal;

    cout << '\n';

    cout << "Dear Professor " << instructor_name << ",\n"
         << '\n'
         << "I am sorry that I am unable to turn in my homework at this time. "
         << "First, I ate a rotten " << food << ", which made me turn " << color
         << " and extremely ill. I came down with a fever of " << number
         << ". Next, my " << adjective << " pet " << animal
         << " must have smelled the remains of the " << food
         << " on my homework because he at it. "
         << "I am currently rewriting my homework and hope you will accept it "
            "late.\n"
         << '\n'
         << "Sincerely,\n"
         << '\n'
         << your_name << '\n';

    return 0;
}
