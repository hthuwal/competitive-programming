/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/longest-palindromic-subsequence       */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[l][i] --> length of LPS in s[i:i+l-1]
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) dp[i][j] = 0;

        // 1 length string is a palindrome
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            dp[1][i] = 1;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                dp[l][i] = max(dp[l - 1][i], dp[l - 1][i + 1]);
                if (s[i] == s[i + l - 1]) {
                    dp[l][i] = max(dp[l][i], dp[l - 2][i + 1] + 2);
                }

                if (dp[l][i] > maxLength) {
                    maxLength = dp[l][i];
                }
            }
        }

        return maxLength;
    }
};