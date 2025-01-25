#include <iostream>

#define STARTING_INTEREST 0.015  // 1.5%
#define NORMAL_INTEREST 0.01     // 1.0%
#define INTEREST_CAP 1000.0      // $1,000.00
#define MINIMUM_CHUNK 10.0       // #10.00

int main() {
    char proceed{'y'};

    while (proceed == 'y' || proceed == 'Y') {
        // Get account balance from user
        std::cout << "Account balance: $";
        float account_balance{};
        std::cin >> account_balance;

        // Calculate total interest
        float total_interest{};
        if (account_balance <= INTEREST_CAP) {
            total_interest = account_balance * STARTING_INTEREST;
        } else {
            total_interest = INTEREST_CAP * STARTING_INTEREST +
                             (account_balance - INTEREST_CAP) * NORMAL_INTEREST;
        }

        // Calculate total balance
        float total_balance{account_balance + total_interest};

        // Calculate minimum payment
        float minimum_payment{};
        if (total_balance <= MINIMUM_CHUNK) {
            minimum_payment = total_balance;
        } else {
            minimum_payment = total_balance / 10;
            if (minimum_payment < MINIMUM_CHUNK) {
                minimum_payment = MINIMUM_CHUNK;
            }
        }

        // Calculate balance after minimum payment
        float balance_after_min_pay{total_balance - minimum_payment};

        // Adjust output floating point precision
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);

        // Display results
        std::cout << "Total Interest:    $" << total_interest << '\n';
        std::cout << "Total Balance:     $" << total_balance << '\n';
        std::cout << "Minimum Payment:   $" << minimum_payment << '\n';
        std::cout << "Balance After Min: $" << balance_after_min_pay << '\n';

        // Prompt user whether or not to proceed
        std::cout << "Proceed? (y/n): ";
        std::cin >> proceed;
    }

    return 0;
}
