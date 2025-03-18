#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>

using std::istream;
using std::ostream;
using std::vector;

/*
 * @class BigInt
 * @brief A class to represent a massive integer.
 */
class BigInt {
   public:
    /**
     * @brief Default constructor.
     * @details Constructs a new BigInt equal to 0.
     */
    BigInt();

    /**
     * @brief Parameterized constructor
     * @param new_num An integer reperesenting the desired number.
     * @details Takes an integer and adds each digit to digits.
     */
    BigInt(int new_num);

    /**
     * @brief Parameterized constructor
     * @param new_num A vector of integers representing the desired number.
     * @details Takes a vector of integers passed by copy and constructs a new
     *          BigInt with the exact same values.
     */
    BigInt(const vector<int> &new_num);

    /**
     * @brief Parameterized constructor.
     * @param &new_num A vector of characters representing the desired number.
     * @details Takes a vector of characters passed by reference and constructs
     *          a new BigInt with those values.
     */
    BigInt(const vector<char> &new_num);

    /**
     * @brief Parameterized constructor.
     * @param *new_num A C-style array of characters representing a number.
     * @param new_size The size of the provided array.
     * @details Initializes the BigInt to `new_size` digits. Static casts each
     *          char value into an integer and adds it to the num vector.
     */
    BigInt(const char *new_num, size_t new_size);

    // Overload the arithmetic operators: +; -; *;
    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt operator*(const BigInt &other) const;

    // Overload the comparison operators: !; ==; >; <; >=; <=;
    bool operator!() const;
    bool operator==(const BigInt &other) const;
    bool operator>(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;

    // Overload the increment/decrement operators: ++; ++<int>; --; --<int>;
    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);

    // Overload the stream operators: <<; >>;
    friend ostream &operator<<(ostream &stream, const BigInt &big_int);
    friend istream &operator>>(istream &stream, BigInt &big_int);

    // Deconstrutor
    virtual ~BigInt();

   private:
    /*
     * @brief Removes leading zeroes.
     * @details Walks the list from back to front, removing zeroes until it
     *          comes across a different number.
     */
    void removeLeadingZeros();

    bool isNeg;          // Stores whether or not the number is negative.
    vector<int> digits;  // Stores the number (big-endian).
};

#endif
