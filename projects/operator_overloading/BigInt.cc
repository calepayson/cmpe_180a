#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

#include "BigInt.h"

using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using std::reverse;
using std::vector;

/****************
 * CONSTRUCTORS *
 ****************/

// Default constructor.
BigInt::BigInt() : isNeg(false) { digits.push_back(0); }

// Parameterized constructor: int
BigInt::BigInt(int new_num) {
    // Return 0 if empty.
    if (new_num == 0) {
        digits.push_back(0);
        return;
    }

    // Check if input is negative.
    if (new_num < 0) {
        isNeg = true;
        new_num = -new_num;
    } else {
        isNeg = false;
    }

    // Add each digit to digits.
    while (new_num > 0) {
        digits.push_back(new_num % 10);
        new_num /= 10;
    }
}

// Parameterized constructor: vector<int>
BigInt::BigInt(const vector<int> &new_num) {
    // Initialize pointers to the front and back of the new num vector.
    int front_ptr = 0;
    int back_ptr = new_num.size() - 1;

    // Check for leading zeros.
    while (new_num.at(front_ptr) == 0 && front_ptr != back_ptr) {
        front_ptr++;
    }

    // Add each digit to digits, include error handling.
    for (int i = back_ptr; i > front_ptr; i--) {
        int new_digit = new_num.at(i);

        if (0 <= new_digit && new_digit <= 9) {
            digits.push_back(new_digit);
        } else {
            cerr << "Error BigInt::BigInt()" << endl;
            cerr << "Expected an integer within [0, 9]" << endl;
            cerr << "Got: " << new_digit << endl;
        }
    }

    // At the first digit, check if it is negative.
    int firstNum = new_num.at(front_ptr);
    isNeg = (firstNum < 0) ? true : false;
    if (isNeg) {
        firstNum *= -1;
    }

    // Add the first digit to digits.
    if (0 <= firstNum && firstNum <= 9) {
        digits.push_back(firstNum);
    } else {
        cerr << "Error BigInt::BigInt()" << endl;
        cerr << "Expected an integer within [0, 9]" << endl;
        cerr << "Got: " << firstNum << endl;
    }
}

// Parameterized constructor: vector<char>
BigInt::BigInt(const vector<char> &new_num) {
    // Initialize a pointer to the front and back of the vector.
    int front_ptr = 0;
    int back_ptr = new_num.size() - 1;

    // Ignore leading zeros.
    while (new_num.at(front_ptr) == '0' && front_ptr != back_ptr) {
        front_ptr++;
    }

    // Check if the number is negative.
    isNeg = new_num.at(front_ptr) == '-';
    if (isNeg) front_ptr++;

    // Add each digit to digits with error handling.
    for (int i = back_ptr; i >= front_ptr; i--) {
        int new_digit = new_num.at(i) - '0';

        if (0 <= new_digit && new_digit <= 9) {
            digits.push_back(new_digit);
        } else {
            cerr << "Error BigInt::BigInt()" << endl;
            cerr << "Expected an integer within [0, 9]" << endl;
            cerr << "Got: " << static_cast<char>(new_digit + '0') << endl;
        }
    }
}

// Parameterized constructor: char *, int
BigInt::BigInt(const char *new_num, size_t new_size) {
    // Initialize a pointer to the front and back of the vector.
    int front_ptr = 0;
    int back_ptr = new_size - 1;

    // Ignore leading zeros.
    if (new_size <= 0) {
        isNeg = false;
        digits.push_back(0);
        cerr << "Error BigInt::BigInt()" << endl;
        cerr << "new_size must be greater than 0." << endl;
    }

    // Check if the number is negative.
    while (new_num[front_ptr] == '0' && front_ptr != back_ptr) {
        front_ptr++;
    }

    // Add each digit to digits with error handling.
    isNeg = new_num[front_ptr] == '-';
    if (isNeg) front_ptr++;

    for (int i = back_ptr; i >= front_ptr; i--) {
        int new_digit = new_num[i] - '0';

        if (0 <= new_digit && new_digit <= 9) {
            digits.push_back(new_digit);
        } else {
            cerr << "Error BigInt::BigInt()" << endl;
            cerr << "Expected an integer within [0, 9]" << endl;
            cerr << "Got: " << static_cast<char>(new_digit + '0') << endl;
        }
    }
}

/************************
 * ARITHMETIC OPERATORS *
 ************************/

// Overload the operator +
BigInt BigInt::operator+(const BigInt &other) const {
    // If the signs are different use subtraction
    if (isNeg != other.isNeg) {
        BigInt absThis = *this;
        BigInt absOther = other;
        absThis.isNeg = false;
        absOther.isNeg = false;

        if (absThis > absOther) {
            BigInt result = absThis - absOther;
            result.isNeg = isNeg;
            return result;
        } else {
            BigInt result = absOther - absThis;
            result.isNeg = other.isNeg;
            return result;
        }
    }

    // Initialize helper variables.
    BigInt result;
    result.digits.clear();
    int carry = 0;
    int maxLength = (digits.size() >= other.digits.size())
                        ? digits.size() + 1
                        : other.digits.size() + 1;

    // Add each digit while keeping track of the carry.
    for (int i = 0; i < maxLength; i++) {
        int sum = carry;
        if (i < (int)digits.size()) sum += digits.at(i);
        if (i < (int)other.digits.size()) sum += other.digits.at(i);

        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }

    result.isNeg = isNeg;  // We've already checked if both number's signs match
    result.removeLeadingZeros();
    return result;
}

// Overload the operator -
BigInt BigInt::operator-(const BigInt &other) const {
    // If the signs are different, use addition
    if (isNeg != other.isNeg) {
        BigInt absThis = *this;
        BigInt absOther = other;
        absThis.isNeg = false;
        absOther.isNeg = false;

        BigInt result = absThis + absOther;
        result.isNeg = isNeg;
        return result;
    }

    // Find which BigInt is larger.
    bool thisLarger = false;
    if (digits.size() != other.digits.size()) {
        thisLarger = digits.size() > other.digits.size();
    } else {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits.at(i) != other.digits.at(i)) {
                thisLarger = digits.at(i) > other.digits.at(i);
                break;
            }
        }
    }

    // Make copies of each to simplify calculations.
    //     Note: It's inneficient to make a copy of each number but massively
    //     reduces the complexity. If it's running slow, tinker with this
    //     method.
    BigInt larger, smaller;
    bool resultNeg;
    if (thisLarger) {
        larger = *this;
        smaller = other;
        resultNeg = isNeg;
    } else {
        larger = other;
        smaller = *this;
        resultNeg = !isNeg;
    }

    // Initialize the result.
    BigInt result;
    result.digits.clear();

    // Perform the subtraction, this was a pain in the butt.
    int borrow = 0;
    for (int i = 0; i < (int)larger.digits.size(); ++i) {
        int diff = larger.digits.at(i) - borrow;
        if (i < (int)smaller.digits.size()) diff -= smaller.digits.at(i);

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits.push_back(diff);
    }

    result.isNeg = resultNeg;
    result.removeLeadingZeros();
    return result;
}

// Overload the operator *
BigInt BigInt::operator*(const BigInt &other) const {
    // If one of the numbers is zero...
    if ((digits.size() == 1 && digits.at(0) == 0) ||
        (other.digits.size() == 1 && other.digits.at(0) == 0)) {
        return BigInt();
    }

    // Max size is at most the sum of the two sizes.
    BigInt result;
    result.digits.resize(digits.size() + other.digits.size());

    // Long multiplication (an absolute pain in the butt)
    for (int i = 0; i < (int)digits.size(); i++) {
        int carry = 0;
        for (int j = 0; j < (int)other.digits.size() || carry; j++) {
            long long current =
                result.digits.at(i + j) +
                static_cast<long long>(digits.at(i)) *
                    (j < (int)other.digits.size() ? other.digits.at(j) : 0) +
                carry;
            result.digits.at(i + j) = current % 10;
            carry = current / 10;
        }
    }

    result.isNeg = isNeg != other.isNeg;
    result.removeLeadingZeros();
    return result;
}

/************************
 * COMPARISON OPERATORS *
 ************************/

// Overload operator !
bool BigInt::operator!() const {
    return !(digits.size() == 1 && digits.at(0) == 0);
}

// Overload operator ==
bool BigInt::operator==(const BigInt &other) const {
    // Check if we can return early based on O(1) attributes
    if (isNeg != other.isNeg) return false;
    if (digits.size() != other.digits.size()) return false;

    // Check that all digits match
    for (int i = 0; i < (int)digits.size(); i++) {
        if (digits.at(i) != other.digits.at(i)) return false;
    }

    return true;
}

// Overload operator >
bool BigInt::operator>(const BigInt &other) const {
    // Check if we can return early based on O(1) attributes.
    if (isNeg && !other.isNeg) return false;
    if (!isNeg && other.isNeg) return true;
    if (!isNeg && digits.size() > other.digits.size()) return true;
    if (isNeg && digits.size() > other.digits.size()) return false;

    // Walk through the digits.
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits.at(i) != other.digits.at(i)) {
            if (isNeg) {
                return (digits.at(i) < other.digits.at(i));
            } else {
                return (digits.at(i) > other.digits.at(i));
            }
        }
    }

    return false;
}

// Overload operator <
bool BigInt::operator<(const BigInt &other) const {
    // Check if we can return early based on O(1) attributes.
    if (isNeg && !other.isNeg) return true;
    if (!isNeg && other.isNeg) return false;
    if (!isNeg && digits.size() < other.digits.size()) return true;
    if (isNeg && digits.size() < other.digits.size()) return false;

    // Walk through the digits.
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits.at(i) != other.digits.at(i)) {
            if (isNeg) {
                return (digits.at(i) > other.digits.at(i));
            } else {
                return (digits.at(i) < other.digits.at(i));
            }
        }
    }

    return false;
}

// Overload operator >=
bool BigInt::operator>=(const BigInt &other) const {
    return (*this > other || *this == other);
}

// Overload operator <=
bool BigInt::operator<=(const BigInt &other) const {
    return (*this < other || *this == other);
}

/*********************************
 * INCREMENT/DECREMENT OPERATORS *
 *********************************/

// Overload operator ++/
BigInt &BigInt::operator++() {
    *this = *this + BigInt(1);
    return *this;
}

// Overload operator /++
BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    ++(*this);
    return temp;
}

// Overload operator --/
BigInt &BigInt::operator--() {
    *this = *this - BigInt(1);
    return *this;
}

// Overload operator /--
BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    --(*this);
    return temp;
}

/********************
 * STREAM OPERATORS *
 ********************/

// Overload the operator <<
ostream &operator<<(ostream &stream, const BigInt &big_int) {
    // Return 0 if the number is not initialized.
    int size = big_int.digits.size();
    if (size <= 0) {
        stream << '0';
        return stream;
    }

    // Return the sign if negative
    if (big_int.isNeg) {
        stream << '-';
    }

    // Iterate through the number and add each short to stream.
    for (int i = size - 1; i >= 0; i--) {
        stream << big_int.digits.at(i);
    }

    return stream;
}

// Overload the operator >>
istream &operator>>(istream &stream, BigInt &big_int) {
    // Clear the digits.
    big_int.digits.clear();

    // To store each character in the stream.
    char ch;

    // Handle a leading negative sign.
    stream >> ch;
    if (ch == '-') {
        big_int.isNeg = true;
    } else {
        big_int.isNeg = false;
        stream.putback(ch);
    }

    // Iterate through each character and attempt to add it to num.
    while (stream >> ch && ch != ' ') {
        if (isdigit(ch)) {
            short digit = ch - '0';
            big_int.digits.push_back(digit);
        } else {
            cerr << "Error BigInt::operator>>" << endl;
            cerr << "Expected an integer within [0, 9]" << endl;
            cerr << "Got: " << ch << endl;
            stream.putback(ch);
            return stream;
        }
    }

    // Reverse the vector to align with little-endian storage.
    reverse(big_int.digits.begin(), big_int.digits.end());

    return stream;
}

/*****************
 * DESTRUCTOR *
 *****************/

// Destructor
BigInt::~BigInt() {}

/*******************
 * PRIVATE METHODS *
 *******************/

// Removes leading zeroes
void BigInt::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }

    if (digits.size() == 1 && digits.at(0) == 0) {
        isNeg = false;
    }
}
