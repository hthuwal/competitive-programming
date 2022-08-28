/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/jump-game-ii/                */
/* -------------------------------------------------------------------------- */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];

        for (int i = 0; i < n; i++) {
            dp[i] = INT_MAX;
        }

        dp[0] = 0;
        int reachability = 0;
        for (int i = 0; i < n; i++) {
            int j = reachability;
            reachability = max(reachability, i + nums[i]);
            for (; j < n && j <= reachability; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};

int main() {
    vector<int> jumps = {2, 3, 1, 1, 4};
    cout << Solution().jump(jumps) << "\n";

    jumps = {2, 3, 0, 1, 4};
    cout << Solution().jump(jumps) << "\n";
}