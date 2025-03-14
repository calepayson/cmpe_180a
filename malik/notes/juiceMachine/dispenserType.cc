#include "dispenserType.h"

int dispenserType::getNoOfItems() const { return numberOfItems; }

int dispenserType::getCost() const { return cost; }

void dispenserType::makeSale() { numberOfItems--; }

dispenserType::dispenserType() : numberOfItems(50), cost(50) {}

dispenserType::dispenserType(int setNoOfItems, int setCost)
    : numberOfItems(setNoOfItems), cost(setCost) {}
