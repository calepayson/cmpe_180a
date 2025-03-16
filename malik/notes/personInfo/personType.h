//*****************************************************************************
// Author: Cale Smith (via D.S. Malik)
//
// class personType
// This class specifies the members to implement a name.
//*****************************************************************************

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

using std::string;

class personType {
   public:
    // Function to output the  first name and last name in the form firstName
    // lastName
    void print() const;

    // Function to set firstName and lastName according to the parameters
    // Postcondition: firstName = first; lastName = last
    void setName(string first, string last);

    // Function to return the first name.
    // Postcondition: The value of firstName is returned.
    string getFirstName() const;

    // Function to return the last name.
    // Postcondition: The value of lastName is returned.
    string getLastName() const;

    // Default constructor
    // Sets firstName and lastName to null strings.
    // Postcondition: firstName = ""; lastName = ""
    personType();

    // Parameterized constructor
    // Sets firstName and lastName according to the parameters.
    // Postcondition: firstname = first; lastName = last;
    personType(string first, string last);

   private:
    string firstName;
    string lastName;
};

#endif
