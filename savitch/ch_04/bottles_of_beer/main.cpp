#include <iostream>
#include <string>

using namespace std;

string num_to_str(int num);
// Takes a number within [0, 99] and returns a string representation of it.
// Example: num_to_str(99) -> "Ninety-Nine";

void print_stanza(int num);
// Takes an int representing a number of bottles and prints the stanza for that
// number.

int main() {
    for (int i = 99; i > 0; i--) {
        print_stanza(i);
    }

    return 0;
}

string num_to_str(int num) {
    int tens_place, ones_place;
    string ten_str, ones_str, full_str;

    tens_place = num / 10;
    ones_place = num % 10;

    // Edge case for zero
    if (tens_place == 0 && ones_place == 0) return "Zero";

    // Edgecases for the 'teens'
    if (tens_place == 1) {
        if (ones_place == 9)
            return "Nineteen";
        else if (ones_place == 8)
            return "Eighteen";
        else if (ones_place == 7)
            return "Seventeen";
        else if (ones_place == 6)
            return "Sixteen";
        else if (ones_place == 5)
            return "Fifteen";
        else if (ones_place == 4)
            return "Fourteen";
        else if (ones_place == 3)
            return "Thirteen";
        else if (ones_place == 2)
            return "Twelve";
        else if (ones_place == 1)
            return "Eleven";
        else if (ones_place == 0)
            return "Ten";
    }

    // Construct tens_place string
    switch (tens_place) {
        case 9:
            ten_str = "Ninety";
            break;
        case 8:
            ten_str = "Eighty";
            break;
        case 7:
            ten_str = "Seventy";
            break;
        case 6:
            ten_str = "Sixty";
            break;
        case 5:
            ten_str = "Fifty";
            break;
        case 4:
            ten_str = "Forty";
            break;
        case 3:
            ten_str = "Thirty";
            break;
        case 2:
            ten_str = "Twenty";
            break;
        default:
            ten_str = "";
            break;
    }

    // Construct ones_place string
    if (ones_place == 9)
        ones_str = "Nine";
    else if (ones_place == 8)
        ones_str = "Eight";
    else if (ones_place == 7)
        ones_str = "Seven";
    else if (ones_place == 6)
        ones_str = "Six";
    else if (ones_place == 5)
        ones_str = "Five";
    else if (ones_place == 4)
        ones_str = "Four";
    else if (ones_place == 3)
        ones_str = "Three";
    else if (ones_place == 2)
        ones_str = "Two";
    else if (ones_place == 1)
        ones_str = "One";
    else
        ones_str = "";

    if (tens_place > 0)
        return ten_str + "-" + ones_str;
    else
        return ones_str;
}

void print_stanza(int num) {
    string bottles = num_to_str(num);
    string next_bottles = num_to_str(num - 1);

    cout << bottles << " bottles of beer on the wall,\n"
         << bottles << " bottles of beer,\n"
         << "Take one down, pass it around,\n"
         << next_bottles << " bottles of beer on the wall.\n\n";
}
