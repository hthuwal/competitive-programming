/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/matrix-block-sum               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 1; i < n; i++) mat[i][0] += mat[i - 1][0];
        for (int i = 1; i < m; i++) mat[0][i] += mat[0][i - 1];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r1 = i - k;
                int c1 = j - k;
                int r2 = i + k;
                int c2 = j + k;

                r1 = r1 < 0 ? 0 : r1;
                c1 = c1 < 0 ? 0 : c1;

                r2 = r2 >= n ? n - 1 : r2;
                c2 = c2 >= m ? m - 1 : c2;

                if (r1 == 0 && c1 == 0) {
                    ans[i][j] = mat[r2][c2];
                } else if (r1 == 0) {
                    ans[i][j] = mat[r2][c2] - mat[r2][c1 - 1];
                } else if (c1 == 0) {
                    ans[i][j] = mat[r2][c2] - mat[r1 - 1][c2];
                } else {
                    ans[i][j] = mat[r2][c2] - mat[r1 - 1][c2] - mat[r2][c1 - 1] + mat[r1 - 1][c1 - 1];
                }
            }
        }

        return std::move(ans);
    }
};