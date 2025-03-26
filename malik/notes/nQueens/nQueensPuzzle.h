#ifndef NQUEENSPUZZL_H
#define NQUEENSPUZZL_H

class nQueensPuzzle {
   public:
    // Constructor
    // Postcondition: noOfSolutions = 0; noOfQueens = queens;
    //     queensInRow is a pointer to the array to store the n-tuple
    nQueensPuzzle(int queens = 8);

    // Function to determine whether a queen can be placed in row k and col i.
    // Postcondition: Returns true if a queen can be placed in row k and column
    //     i; otherwise it returns false.
    bool canPlaceQueen(int k, int i);

    // Function to determine all solutions to the n-queens puzzle using
    // backtracking.
    // The function is called with the value 0.
    // Postcondition: All n-tuples representing solutions of n-queens puzzle are
    //     generated and printed.
    void queensConfiguration(int k);

    // Function to output an n-tuple containing a solution to the n-queens
    // puzzle.
    void printConfiguration();

    // Function to return the total number of solutions.
    // Postcondition: The value of noOfSolution is returned.
    int solutionsCount();

   private:
    int noOfSolutions;
    int noOfQueens;
    int *queensInRow;
};

#endif
