/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/edit-distance/                */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] --> minimum number of operations to convert word1[0:i] to word2[0:j];
        int dp[n + 1][m + 1];

        // Converting a 0 length word1 to i length word2 woudld require i insertions
        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }

        // Converting a i length word1 to 0 length word2 woudld require i deletions
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Insert
                int insert = 1 + dp[i][j - 1];

                // Delete
                int del = 1 + dp[i - 1][j];

                // If they are already same, replace would cost 0;
                int replace = dp[i - 1][j - 1];

                if (word1[i - 1] != word2[j - 1]) {
                    // Replace
                    replace++;
                }

                dp[i][j] = min(min(insert, del), replace);
            }
        }

        return dp[n][m];
    }
};

int main() {
    cout<<Solution().minDistance("harish", "rishi")<<"\n";
    cout<<Solution().minDistance("intention", "execution")<<"\n";
}