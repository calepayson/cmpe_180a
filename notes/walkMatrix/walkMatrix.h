#ifndef WALKMATRIX_H
#define WALKMATRIX_H

#include <vector>

using std::vector;

void dfs(const vector<vector<int>> &matrix, vector<vector<int>> &tracker, int i,
         int j);
bool walkMatrix(const vector<vector<int>> &matrix);

void dfs(const vector<vector<int>> &matrix, vector<vector<int>> &tracker, int i,
         int j) {
    if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1) {
        return;
    }
    if (tracker[i][j] == 1 || matrix[i][j] == 1) {
        return;
    }

    tracker[i][j] = 1;
    dfs(matrix, tracker, i - 1, j);
    dfs(matrix, tracker, i + 1, j);
    dfs(matrix, tracker, i, j - 1);
    dfs(matrix, tracker, i, j + 1);
}

bool walkMatrix(const vector<vector<int>> &matrix) {
    int i_size = matrix.size();
    int j_size = matrix[0].size();

    vector<vector<int>> tracker;
    tracker.resize(i_size);
    for (int i = 0; i < i_size; i++) {
        tracker[i].resize(j_size, 0);
    }

    dfs(matrix, tracker, 0, 0);

    return (tracker[i_size - 1][j_size - 1] == 1);
}

#endif
