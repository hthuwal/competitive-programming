/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/unique-paths                 */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    // Time(O(m*n)), Space(O(m*n))
    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int dp[m][n];
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // Time(O(m*n)), Space(O(n))
    int uniquePaths2(int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int dp[1][n];
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            int this_row_prev_column = dp[0][0];
            for (int j = 1; j < n; j++) {
                dp[0][j] += this_row_prev_column;

                // Shift and move it upward
                this_row_prev_column = dp[0][j];
            }
        }
        return dp[0][n - 1];
    }
};

int main() { cout << Solution().uniquePaths(7, 7) << endl; }