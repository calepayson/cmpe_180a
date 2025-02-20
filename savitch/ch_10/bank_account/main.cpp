#include <cmath>
#include <iostream>

class BankAccount {
   public:
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();

    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);

    void update();

    double get_balance();

    double get_rate();

    void output(std::ostream &outs);

   private:
    int dollar_part;
    int cents_part;
    double interest_rate;

    double fraction(double percent);

    double percent(double fraction_value);
};

int main() {
    using std::cout;

    BankAccount account1(100, 2.3), account2;

    cout << "account1 initialized as follows:\n";
    account1.output(cout);
    cout << "account2 initialized as follows:\n";
    account2.output(cout);

    account1 = BankAccount(999, 99, 5.5);
    cout << "account1 reset to the following:\n";
    account1.output(cout);

    return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate) {
    using std::cout;

    if ((dollars < 0) || (cents < 0) || (rate < 0)) {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollar_part = dollars;
    cents_part = cents;
    interest_rate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate) {
    using std::cout;

    if ((dollars < 0) || (rate < 0)) {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollar_part = dollars;
    cents_part = 0;
    interest_rate = fraction(rate);
}

BankAccount::BankAccount()
    : dollar_part(0), cents_part(0), interest_rate(0.0) {}

double BankAccount::fraction(double percent_value) {
    return (percent_value / 100.0);
}

void BankAccount::update() {
    double balance = get_balance();
    balance = balance + (interest_rate * balance);
    dollar_part = static_cast<int>(floor(balance));
    cents_part = static_cast<int>(floor(balance - dollar_part) * 100);
}

double BankAccount::get_balance() {
    return (dollar_part + (cents_part * 0.01));
}

double BankAccount::percent(double fraction_value) {
    return fraction_value * 100;
}

double BankAccount::get_rate() { return percent(interest_rate); }

void BankAccount::output(std::ostream &outs) {
    using std::endl;

    outs.setf(std::ios::fixed);
    outs.setf(std::ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << get_balance() << endl;
    outs << "Interest rate " << get_rate() << "%" << endl;
}

void BankAccount::set(int dollars, int cents, double rate) {
    using std::cout;

    if ((dollars < 0) || (cents < 0) || (rate < 0)) {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollar_part = dollars;
    cents_part = cents;
    interest_rate = fraction(rate);
}

void BankAccount::set(int dollars, double rate) {
    using std::cout;

    if ((dollars < 0) || (rate < 0)) {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollar_part = dollars;
    cents_part = 0;
    interest_rate = fraction(rate);
}
