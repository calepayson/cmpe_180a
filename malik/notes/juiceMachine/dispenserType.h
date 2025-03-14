//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// class dispensertype
// This class specifies the members to implement a dispenser.
//*****************************************************************************

#ifndef DISPENSERTYPE_H
#define DISPENSERTYPE_H

class dispenserType {
   public:
    // Function to show the number of items in the machine.
    // Postcondition: The value of numberOfItems is returned.
    int getNoOfItems() const;

    // Function to show the cost of the item.
    // Postcondition: The value of cost is returned.
    int getCost() const;

    // Function to reduce the number of items by 1.
    // Postcondition: numberOfItems--;
    void makeSale();

    // Default constructor
    // Sets the cost and number of items in the dispenser to 50.
    // Postconditon: numberOfItems = 50; cost = 50
    dispenserType();

    // Parameterized constructor
    // Sets the cost and number of items in the dispenser to the values
    // specified by the user.
    // Postconditon: numberOfItem = setNoOfItems; cost = setCost;
    dispenserType(int setNoOfItems, int setCost);

   private:
    int numberOfItems;
    int cost;
};

#endif
