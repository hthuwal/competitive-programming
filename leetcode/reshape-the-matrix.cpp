/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/reshape-the-matrix/             */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        if (n * m != r * c || (n == r && m == c)) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int flattenedIndex = m * i + j;
                int deflattenRow = flattenedIndex / c;
                int deflattenCol = flattenedIndex % c;
                ans[deflattenRow][deflattenCol] = mat[i][j];
            }
        }
        return std::move(ans);
    }
};