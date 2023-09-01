/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/set-matrix-zeroes              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(201, false);
        vector<bool> col(201, false);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < 201; i++) {
            if (row[i]) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < 201; j++) {
            if (col[j]) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};