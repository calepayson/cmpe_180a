#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

using std::vector;

class ticTacToe {
   public:
    // Function to print the current state of the board
    // Postcondition: Prints the board to std::cout
    void printBoard() const;

    // Function to check if there's a winner
    // Postcondition: Returns 1 if player1 has won, 2 if player2 has won, 0 if
    //     no player has won, and 3 if it's a tie.
    int getWinner() const;

    // Function to get a move from a player
    // Postcondition: Updates the board with the player's move.
    void getMove();

    // Function to get the current player:
    // Postcondition: Returns the current player.
    int getPlayer() const;

    // Default constructor
    // Defines an empty board and sets turn to player1.
    // Postcondition: board initialized to 0. player1 = true.
    ticTacToe();

   private:
    vector<vector<int>> board;
    int player;
    vector<char> tokens = {' ', 'X', 'O'};
};

#endif
