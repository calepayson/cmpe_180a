#include <iostream>

#include "ticTacToe.h"

using std::cin;
using std::cout;
using std::endl;

void ticTacToe::printBoard() const {
    int size = 3;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ' ' << tokens.at(board[i][j]) << ' ';
            if (j + 1 != size) cout << '|';
        }
        cout << endl;
        if (i + 1 != size) cout << "---|---|---" << endl;
    }
}

int ticTacToe::getWinner() const {
    int size = 3;
    for (int i = 0; i < size; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
            board[i][0] != 0) {
            return board[i][0];
        }
    }
    for (int j = 0; j < size; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] &&
            board[0][j] != 0) {
            return board[0][j];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != 0) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != 0) {
        return board[0][2];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) return 0;
        }
    }
    return 3;
}

void ticTacToe::getMove() {
    int row, col;
    bool valid = false;

    while (!valid) {
        cout << "Row: ";
        cin >> row;
        cout << "Col: ";
        cin >> col;

        bool valid_row = 0 < row && row < 4;
        bool valid_col = 0 < col && col < 4;
        if (!valid_row || !valid_col) {
            cout << "Row and Column numbers must be within [1, 3]" << endl;
        } else {
            row--;
            col--;

            if (board[row][col] != 0) {
                cout << "That space is full" << endl;
            } else {
                board[row][col] = player;
                player = (player == 1) ? 2 : 1;
                return;
            }
        }
    }
}

int ticTacToe::getPlayer() const { return player; }

ticTacToe::ticTacToe() {
    int size = 3;
    board.resize(size, vector<int>(size, 0));
    player = 1;
}
