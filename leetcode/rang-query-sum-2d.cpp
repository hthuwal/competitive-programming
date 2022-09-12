/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/range-sum-query-2d-immutable         */
/* -------------------------------------------------------------------------- */
#include <iostream>
#include <vector>

using namespace std;

/* ------------- O(n^2) initialization, O(row2-row1) per query -------------- */
class NumMatrix {
   private:
    vector<vector<int>>& matrix;

   public:
    // matrix[i][j] --> denotes the sum of all elements in ith row from 0 to j
    NumMatrix(vector<vector<int>>& matrix_) : matrix(matrix_) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (j != 0) {
                    matrix[i][j] += matrix[i][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += matrix[i][col2];
            if (col1 != 0) {
                ans -= matrix[i][col1 - 1];
            }
        }
        return ans;
    }
};

/* -------------------- O(n^2) initialization, O(1) query ------------------- */
class NumMatrixFaster {
   private:
    vector<vector<int>>& matrix;

   public:
    // matrix[i][j] --> denotes the sum of entire matrix with top left at (0,0) and bottom right at (i, j)
    NumMatrixFaster(vector<vector<int>>& matrix_) : matrix(matrix_) {
        for (int i = 1; i < matrix.size(); i++) {
            matrix[i][0] += matrix[i - 1][0];
        }

        for (int j = 1; j < matrix[0].size(); j++) {
            matrix[0][j] += matrix[0][j - 1];
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return matrix[row2][col2];
        } else if (row1 == 0) {
            return matrix[row2][col2] - matrix[row2][col1 - 1];
        } else if (col1 == 0) {
            return matrix[row2][col2] - matrix[row1 - 1][col2];
        } else {
            return matrix[row2][col2] - matrix[row1 - 1][col2] - matrix[row2][col1 - 1] + matrix[row1 - 1][col1 - 1];
        }
    }
};