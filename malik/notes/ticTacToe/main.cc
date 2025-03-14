#include <iostream>

#include "ticTacToe.h"

using std::cout;
using std::endl;

int main() {
    ticTacToe game;

    while (game.getWinner() == 0) {
        game.printBoard();
        cout << endl;
        cout << "Current Player: " << game.getPlayer() << endl;
        cout << endl;
        game.getMove();
        cout << endl;
    }

    game.printBoard();

    switch (game.getWinner()) {
        case 1:
            cout << "Player 1 wins!" << endl;
            break;
        case 2:
            cout << "Player 2 wins!" << endl;
            break;
        case 3:
            cout << "Tie game!" << endl;
            break;
        default:
            cout << "I have no idea what's going on! Good luck debugging!"
                 << endl;
            break;
    }

    return 0;
}
