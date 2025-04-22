#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>

using std::ostream;

struct llNode {
    int data;
    llNode *prev;
    llNode *next;
};

enum ClockDirection { ClockWise, CounterClockWise };

class CircularLinkedList {
   public:
    // Default Constructor
    CircularLinkedList();

    // Destructor
    virtual ~CircularLinkedList();

    // push: Insert a new node containing the integer provided in the d
    // direction.
    void push(int i, ClockDirection d);

    // pop: Removes the head node and returns its value and sets the head in the
    // direction specified in d.
    int pop(ClockDirection d);

    // peek: Return the integer in the head of the circular list.
    int peek() const;

    // rotate: Rotate the head pointer n spaces in the direction specified in d.
    void rotate(unsigned int n, ClockDirection d);

    // Overload << operator
    friend ostream &operator<<(ostream &os, const CircularLinkedList &list);

   protected:
    llNode *head;

   private:
    void push_to_list(int i, ClockDirection d);

    int pop_from_list(ClockDirection d);

    int peek_at_list() const;

    void rotate_list(unsigned int n, ClockDirection d);

    void destroy_list();
};

#endif
