/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/longest-palindromic-substring        */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[l][i] --> true if s[i:i+l-1] is a palindrome
        bool dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) dp[i][j] = false;

        // All strings of unit length are palindrome
        for (int i = 0; i < n; i++) {
            dp[1][i] = true;
        }

        int start_ans = 0;
        int length_ans = 1;

        // All string of 2 length
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                start_ans = i;
                length_ans = 2;
                dp[2][i] = true;
            }
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                dp[l][i] = dp[l - 2][i + 1] && (s[i] == s[i + l - 1]);
                if (dp[l][i]) {
                    start_ans = i;
                    length_ans = l;
                }
            }
        }

        return s.substr(start_ans, length_ans);
    }
};