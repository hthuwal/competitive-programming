/* -------------------------------------------------------------------------- */
/*          https://leetcode.com/problems/unique-binary-search-trees          */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;  // Number of BSTs with zero nodes = 1
        dp[1] = 1;  // Number of BSTs with 1 node = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = 0;

            // j -> number of nodes in left subtree
            // i-j-1 -> number of nodes in right subtree
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};