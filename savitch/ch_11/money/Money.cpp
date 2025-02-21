#include "Money.h"

Money operator+(Money amount1, Money amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(Money amount1, Money amount2) {
    return amount1.all_cents == amount2.all_cents;
}

Money::Money(long dollars, int cents) { all_cents = (dollars * 100) + cents; }

Money::Money(long dollars) { all_cents = dollars * 100; }

Money::Money() { all_cents = 0; }

double Money::get_value() { return all_cents * 0.01; }

void Money::input(std::istream &ins) {}

void Money::output(std::ostream &outs) {}
