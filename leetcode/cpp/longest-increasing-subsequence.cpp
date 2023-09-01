#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:

    /* ------------------------- O(n^2) time, O(n) space ------------------------ */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }

        // dp[i] -> lis for nums[0:i] where you have to include nums[i]
        int dp[n];

        dp[0] = 1;
        dp[1] = 2 ? nums[1] > nums[0] : 1;

        int ans = max(dp[1], dp[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};