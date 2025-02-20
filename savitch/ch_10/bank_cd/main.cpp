#include <iostream>

struct CDAccount {
    double balance;
    double interest_rate;
    int term;  // Months until maturity
};

void get_data(CDAccount &the_account);

int main() {
    using std::cout;
    using std::endl;

    CDAccount account;
    get_data(account);

    double rate_fraction, interest;
    rate_fraction = account.interest_rate / 100.0;
    interest = account.balance * rate_fraction * (account.term / 12.0);
    account.balance = account.balance + interest;

    cout.setf(std::ios::fixed);
    cout.setf(std::ios::showpoint);
    cout.precision(2);
    cout << "When your CD matures in " << account.term << " months, \n"
         << "it will have a balance of $" << account.balance << endl;

    return 0;
}

void get_data(CDAccount &the_account) {
    using std::cin;
    using std::cout;

    cout << "Enter account balance: $";
    cin >> the_account.balance;
    cout << "Enter account interest rate: ";
    cin >> the_account.interest_rate;
    cout << "Enter the number of months until maturity\n"
         << "(must be 12 or fewer months): ";
    cin >> the_account.term;
}
