/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/maximal-square                */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // dp[i][j] = the side of maximal square whose bottom right corners is at i,j
        int dp[n][m];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = matrix[i][j] - '0';
                ans = max(ans, dp[i][j]);
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i][j] == 1) {
                    int above = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    int diagonal = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(min(above, left), diagonal);
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};