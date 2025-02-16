#include <iostream>
#include <string>

std::string to_pig_latin(std::string name);

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string first_name, last_name, pig_latin;

    cout << "Enter your first and last name: ";
    cin >> first_name >> last_name;

    pig_latin = to_pig_latin(first_name) + " " + to_pig_latin(last_name);

    cout << "Your name in pig latin is: " << pig_latin << endl;

    return 0;
}

std::string to_pig_latin(std::string name) {
    using std::string;

    bool starts_with_vowel = name[0] == 'a' || name[0] == 'e' ||
                             name[0] == 'i' || name[0] == 'o' ||
                             name[0] == 'u' || name[0] == 'y';

    if (starts_with_vowel) {
        name.append("way");
    } else {
        char first_letter = name[0];
        string new_name;
        int length = static_cast<int>(name.size());
        for (int i = 1; i < length; i++) {
            new_name = new_name + name[i];
        }
        name = new_name + first_letter + "jay";
    }

    return name;
}
