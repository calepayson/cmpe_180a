#include <iostream>

#include "BigInt.h"

using std::cout;
using std::endl;

void testConstructionAndNegatives();
void testConstructionAndOutput();
void testAddition();
void testSubtraction();
void testMultiplication();
void testComparisons();
void testIncrementDecrement();

int main() {
    // testConstructionAndNegatives();
    // cout << endl;
    testConstructionAndOutput();
    cout << endl;
    testAddition();
    cout << endl;
    testSubtraction();
    cout << endl;
    testMultiplication();
    cout << endl;
    testComparisons();
    cout << endl;
    testIncrementDecrement();

    return 0;
}

void testConstructionAndNegatives() {
    cout << "=============================================" << endl;
    cout << "Construction and Negatives" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "0" << endl;
    cout << "Got:" << endl;
    BigInt bigint1;
    cout << bigint1 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "-123" << endl;
    cout << "Got:" << endl;
    vector<int> num2 = {-1, 2, 3};
    BigInt bigint2(num2);
    cout << bigint2 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "-123" << endl;
    cout << "Got:" << endl;
    vector<char> num3 = {'-', '1', '2', '3'};
    BigInt bigint3(num3);
    cout << bigint3 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "-123" << endl;
    cout << "Got:" << endl;
    char num4[] = "-123";
    BigInt bigint4(num4, sizeof(num4) - 1);
    cout << bigint4 << endl;
    cout << "=============================================" << endl;
}

void testConstructionAndOutput() {
    cout << "=============================================" << endl;
    cout << "Construction and << Overload " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected: " << endl;
    cout << "bigint1: 12345678901234567890" << endl;
    cout << "Got: " << endl;
    char num1[] = "12345678901234567890";
    BigInt bigint1(num1, sizeof(num1) - 1);
    cout << "bigint1: " << bigint1 << endl;
    cout << "=============================================" << endl;
}

void testAddition() {
    cout << "=============================================" << endl;
    cout << "Addition" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected: " << endl;
    cout << "111111111011111111100" << endl;
    cout << "Got:" << endl;
    char num1[] = "12345678901234567890";
    char num2[] = "98765432109876543210";
    BigInt bigint1(num1, sizeof(num1) - 1);
    BigInt bigint2(num2, sizeof(num2) - 1);
    cout << bigint1 + bigint2 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "-2000" << endl;
    cout << "Got:" << endl;
    std::vector<int> num3 = {-5, 0, 0, 0};
    std::vector<char> num4 = {'3', '0', '0', '0'};
    BigInt bigint3(num3);
    BigInt bigint4(num4);
    cout << bigint3 + bigint4 << endl;
    cout << "=============================================" << endl;
}

void testSubtraction() {
    cout << "=============================================" << endl;
    cout << "Subtraction" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected: " << endl;
    cout << "1" << endl;
    cout << "Got:" << endl;
    char num1[] = "100000000000000000000";
    char num2[] = "99999999999999999999";
    BigInt bigint1(num1, sizeof(num1) - 1);
    BigInt bigint2(num2, sizeof(num2) - 1);
    cout << bigint1 - bigint2 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected:" << endl;
    cout << "-8000" << endl;
    cout << "Got:" << endl;
    std::vector<char> num3 = {'-', '5', '0', '0', '0'};
    std::vector<int> num4 = {3, 0, 0, 0};
    BigInt bigint3(num3);
    BigInt bigint4(num4);
    cout << bigint3 - bigint4 << endl;
    cout << "=============================================" << endl;
}
void testMultiplication() {
    cout << "=============================================" << endl;
    cout << "Multiplication" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected: " << endl;
    cout << "83810205" << endl;
    cout << "Got:" << endl;
    char num1[] = "12345";
    char num2[] = "6789";
    BigInt bigint1(num1, sizeof(num1) - 1);
    BigInt bigint2(num2, sizeof(num2) - 1);
    cout << bigint1 * bigint2 << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Expected: " << endl;
    cout << "-83810205" << endl;
    cout << "Got:" << endl;
    char num3[] = "-12345";
    char num4[] = "6789";
    BigInt bigint3(num3, sizeof(num3) - 1);
    BigInt bigint4(num4, sizeof(num4) - 1);
    cout << bigint3 * bigint4 << endl;
    cout << "=============================================" << endl;
}
void testComparisons() {
    cout << "=============================================" << endl;
    cout << "Comparisons" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "All of the following should output True" << endl;
    char num1[] = "1234567890";
    char num2[] = "9876543210";
    char num3[] = "1234567890";
    BigInt bi1(num1, sizeof(num1) - 1);
    BigInt bi2(num2, sizeof(num2) - 1);
    BigInt bi3(num3, sizeof(num3) - 1);
    cout << bi1 << " == " << bi3 << " -> " << ((bi1 == bi3) ? "true" : "false")
         << endl;
    cout << bi1 << " < " << bi2 << " -> " << ((bi1 < bi2) ? "true" : "false")
         << endl;
    cout << bi2 << " > " << bi1 << " -> " << ((bi2 > bi1) ? "true" : "false")
         << endl;
    cout << bi1 << " <= " << bi3 << " -> " << ((bi1 <= bi3) ? "true" : "false")
         << endl;
    cout << bi1 << " >= " << bi3 << " -> " << ((bi1 >= bi3) ? "true" : "false")
         << endl;
    cout << "=============================================" << endl;
}
void testIncrementDecrement() {
    cout << "=============================================" << endl;
    cout << "Increment and Decrement" << endl;
    cout << "---------------------------------------------" << endl;
    vector<int> num = {1, 0, 0};
    BigInt a(num);
    cout << "Format:" << endl;
    cout << "Op  -> exp -> got" << endl;
    cout << "++a -> 101 -> " << ++a << endl;
    cout << "a++ -> 101 -> " << a++ << endl;
    cout << "a   -> 102 -> " << a << endl;
    cout << "--a -> 101 -> " << --a << endl;
    cout << "a-- -> 101 -> " << a-- << endl;
    cout << "a   -> 100 -> " << a << endl;
    cout << "=============================================" << endl;
}
