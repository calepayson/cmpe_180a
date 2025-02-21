#ifndef __MONEY_H__
#define __MONEY_H__

#include <iostream>

class Money {
   public:
    friend Money operator+(Money amount1, Money amount2);
    friend bool operator==(Money amount1, Money amount2);

    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double get_value();
    void input(std::istream &ins);
    void output(std::ostream &outs);

   private:
    long all_cents;
};
#endif
