#include "cashRegister.h"

int cashRegister::getCurrentBalance() const { return cashOnHand; }

void cashRegister::acceptAmount(int amountIn) {
    cashOnHand = cashOnHand + amountIn;
}

cashRegister::cashRegister() : cashOnHand(500) {}

cashRegister::cashRegister(int cash) : cashOnHand(cash) {}
