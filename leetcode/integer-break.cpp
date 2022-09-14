/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/integer-break                */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int integerBreak(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = INT_MIN;
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[i - j] * j);
                dp[i] = max(dp[i], (i - j) * j);
            }
        }
        return dp[n];
    }
};