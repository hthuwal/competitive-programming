/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/combination-sum/               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Infinite Knapsack Problem
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        // dp[i][j] denotes the list of all combinations from candidates[0:i-1] that result in sum of "j"
        vector<vector<int>> dp[n + 1][target + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // All combinations for candidates[0:i-1] that yield to j
                // are valid solutions for candidates[0:i]
                dp[i][j] = dp[i - 1][j];

                // if the (i-1)th value itself is equal to target j
                // then its a valid solution
                if (j == candidates[i - 1]) {
                    dp[i][j].push_back({j});
                }
                // else if (i-1)th value is less then the target j
                else if (j > candidates[i - 1]) {
                    int old_target = j - candidates[i - 1];

                    // valid solutions for achieving sum of old_target using candidates[0:i] i.e dp[i][old_target]
                    // + candidates[i-1] is a valid solution for achieiving target "j"
                    for (auto each : dp[i][old_target]) {
                        each.push_back(candidates[i - 1]);
                        dp[i][j].push_back(std::move(each));
                    }
                }
            }
        }
        return std::move(dp[n][target]);
    }
};

int main() {
    vector<int> arr(30, 0);
    srand(42);
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 200 + 1;
    }
    auto ans = std::move(Solution().combinationSum(arr, 100));
    cout << ans.size();
}