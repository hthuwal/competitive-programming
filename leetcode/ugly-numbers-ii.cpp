/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/ugly-number-ii/               */
/* -------------------------------------------------------------------------- */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }

        int dp[n];

        dp[0] = 1;

        // Index of the ugly number to which 2, 3, and 5 should be multiplied next
        int two = 0;
        int three = 0;
        int five = 0;

        for (int i = 1; i < n; i++) {
            int op2 = dp[two] * 2;
            int op3 = dp[three] * 3;
            int op5 = dp[five] * 5;

            dp[i] = min(op2, min(op3, op5));

            // We multiplied with 2, so next time try the next ugly number
            if (dp[i] == op2) two++;
            if (dp[i] == op3) three++;
            if (dp[i] == op5) five++;
        }

        return dp[n - 1];
    }
};