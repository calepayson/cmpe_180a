#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void fill(int **p, int rowSize, int colSize);
void print(int **p, int rowSize, int colSize);

int main() {
    int **board;

    int rows;
    int cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    cout << endl;

    board = new int *[rows];
    for (int row = 0; row < rows; row++) {
        board[row] = new int[cols]{};
    }

    fill(board, rows, cols);
    print(board, rows, cols);

    for (int row = 0; row < rows; row++) {
        delete[] board[row];
    }

    delete[] board;

    return 0;
}

void fill(int **p, int rowSize, int colSize) {
    int counter = 1;
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            p[row][col] = counter++;
        }
    }
}

void print(int **p, int rowSize, int colSize) {
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            cout << p[row][col] << ' ';
        }
        cout << endl;
    }
}
