/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/wiggle-subsequence/             */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* ------------------------- O(n^2 time), O(n) space ------------------------ */
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        // dp[i] denotes wml in nums[0:i] where you have to include nums[i]
        // signe of the value indicates the value of the last difference
        int dp[n];
        dp[0] = 1;
        int ans = 1;
        
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                int cand = 1;
                if (dp[j] == 1) {
                    cand = nums[i] > nums[j] ? 2 : (nums[i] < nums[j] ? -2 : 1);
                } else if (dp[j] < 0 && nums[i] > nums[j]) {
                    cand = 1 + dp[j] * -1;
                } else if (dp[j] > 0 && nums[i] < nums[j]) {
                    cand = (1 + dp[j]) * -1;
                    ;
                }

                if (abs(cand) > abs(dp[i])) {
                    dp[i] = cand;
                }
            }
            ans = max(abs(dp[i]), ans);
        }

        return ans;
    }
};