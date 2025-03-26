#include <iostream>

#include "nQueensPuzzle.h"

using std::cout;
using std::endl;

nQueensPuzzle::nQueensPuzzle(int queens) : noOfQueens(queens) {
    noOfSolutions = 0;
    queensInRow = new int[noOfQueens];
}

bool nQueensPuzzle::canPlaceQueen(int k, int i) {
    for (int j = 0; j < k; j++) {
        if ((queensInRow[j] == i) || (abs(queensInRow[j] - i) == abs(j - k))) {
            return false;
        }
    }
    return true;
}

void nQueensPuzzle::queensConfiguration(int k) {
    for (int i = 0; i < noOfQueens; i++) {
        if (canPlaceQueen(k, i)) {
            queensInRow[k] = i;
            if (k == noOfQueens - 1) {
                printConfiguration();
            } else {
                queensConfiguration(k + 1);
            }
        }
    }
}

void nQueensPuzzle::printConfiguration() {
    noOfSolutions++;
    cout << "(";
    for (int i = 0; i < noOfQueens - 1; i++) {
        cout << queensInRow[i] << ", ";
    }

    cout << queensInRow[noOfQueens - 1] << ")" << endl;
}

int nQueensPuzzle::solutionsCount() { return noOfSolutions; }
