#include <iostream>

#include "sellProduct.h"

using std::cin;
using std::cout;
using std::endl;

void sellProduct(dispenserType &product, cashRegister &pCounter) {
    int amount;
    int amount2;

    if (product.getNoOfItems() > 0) {
        cout << "Please deposit " << product.getCost() << " cents" << endl;
        cin >> amount;

        if (amount < product.getCost()) {
            cout << "Please deposit another " << product.getCost() - amount
                 << " cents" << endl;
            cin >> amount2;
            amount += amount2;
        }

        if (amount >= product.getCost()) {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and enjoy." << endl;
        } else {
            cout << "The amount is not enough. Collect what you deposited."
                 << endl;
        }
    } else {
        cout << "Sorry this item is sold out." << endl;
    }
}
