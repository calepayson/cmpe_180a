#include <iostream>

#include "cashRegister.h"
#include "dispenserType.h"
#include "sellProduct.h"
#include "showSelection.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cashRegister cash;

    dispenserType appleJuice(100, 50);
    dispenserType orangeJuice(100, 65);
    dispenserType mangoLassi(75, 45);
    dispenserType fruitPunch(100, 85);

    int selection;

    showSelection();

    cin >> selection;

    while (selection != 9) {
        switch (selection) {
            case 1:
                sellProduct(appleJuice, cash);
                break;
            case 2:
                sellProduct(orangeJuice, cash);
                break;
            case 3:
                sellProduct(mangoLassi, cash);
                break;
            case 4:
                sellProduct(fruitPunch, cash);
                break;
            default:
                cout << "Invalid selection." << endl;
        }

        showSelection();
        cin >> selection;
    }

    return 0;
}
