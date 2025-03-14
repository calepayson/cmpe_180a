//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// class cashRegister
// This class specifies the members to implement a cash register.
//*****************************************************************************

#ifndef CASHREGISTER_H
#define CASHREGISTER_H

class cashRegister {
   public:
    // Function to show the current amount in the cash register.
    // Postcondition: The value of cashOnHand is returned.
    int getCurrentBalance() const;

    // Function to recieve the amount deposited by the customer and update the
    // amount in the register.
    // Postconditon: cashOnHand = cashOnHand + amountIn;
    void acceptAmount(int amountIn);

    // Default constructor
    // Sets the cash in the register to 500 cents.
    // Postcondition: cashOnHand = 500.
    cashRegister();

    // Parameterized constructor
    // Sets the cash in the register to a specific amount.
    // Postcondition: cashOnHand = cashIn
    cashRegister(int cashIn);

   private:
    int cashOnHand;
};

#endif
