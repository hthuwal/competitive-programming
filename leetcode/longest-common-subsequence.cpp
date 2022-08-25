/* -------------------------------------------------------------------------- */
/*          https://leetcode.com/problems/longest-common-subsequence/         */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {}