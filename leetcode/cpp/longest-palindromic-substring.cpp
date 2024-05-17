/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/longest-palindromic-substring        */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[i][j]: Denotes if string of length l
        // starting at i is a palindrome
        bool dp[n + 1][n + 1];
        memset(dp, false, sizeof(dp));

        int max_l = 0;
        int start_i = 0;
        for (int l = 0; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                // A string of length 0 or 1 is always a palindrome
                if (l == 1 || l == 0) {
                    dp[l][i] = true;
                } else {
                    int j = i + l - 1;
                    if (s[i] == s[j]) {
                        dp[l][i] = dp[l - 2][i + 1];
                    }
                }

                if (dp[l][i]) {
                    start_i = i;
                    max_l = max(max_l, l);
                }
            }
        }
        return s.substr(start_i, max_l);
    }
};