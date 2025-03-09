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
     * @brief Paramatarized constructor
     * @param new_num A vector of integers representing the desired number.
     * @details Takes a vector of integers passed by copy and constructs a new
     *          BigInt with the exact same values.
     */
    BigInt(const vector<int> &new_num);

    /**
     * @brief Paramatarized constructor.
     * @param &new_num A vector of characters representing the desired number.
     * @details Takes a vector of characters passed by reference and constructs
     *          a new BigInt with those values.
     */
    BigInt(const vector<char> &new_num);

    /**
     * @brief Paramatarized constructor.
     * @param *new_num A C-style array of characters representing a number.
     * @param new_size The size of the provided array.
     * @details Initializes the BigInt to `new_size` digits. Static casts each
     *          char value into an integer and adds it to the num vector.
     */
    BigInt(const char *new_num, size_t new_size);

    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt operator*(const BigInt &other) const;

    bool operator!() const;
    bool operator==(const BigInt &other) const;
    bool operator>(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;

    BigInt &operator++();
    BigInt operator++(int);
    BigInt &operator--();
    BigInt operator--(int);

    friend ostream &operator<<(ostream &stream, const BigInt &big_int);
    friend istream &operator>>(istream &stream, BigInt &big_int);

    virtual ~BigInt();

   private:
    bool neg;
    vector<short> num;
};

#endif
