/* ------------ https://leetcode.com/problems/combination-sum-ii/ ----------- */

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/**
 * Bottom up Dynamic Programming
 **/
class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int final_target) {
        std::sort(candidates.begin(), candidates.end());

        // dp[target][i] --> Possible Solutions to achieve target using candidates[0:i]
        vector<vector<int>> dp[final_target + 1][candidates.size()];

        for (int target = 1; target <= final_target; target++) {
            for (int i = 0; i < candidates.size(); i++) {
                // If its the only element and equals to the target
                if (i == 0 && candidates[i] == target) {
                    dp[target][i] = {{target}};
                } else if (i > 0) {
                    vector<vector<int>> solution;

                    // Try all candidates (kth index) from starting at i till 0 to achieve target
                    for (int k = i; k >= 0; k--) {
                        // skip if the candidate is same as the last one
                        if (k < i && candidates[k] == candidates[k + 1]) {
                            continue;
                        }

                        // If this candidate matches the target
                        if (candidates[k] == target) {
                            solution.push_back({target});
                        }
                        // Get the answer to subproblem, solution of achieving (target-candidates[k]) using the
                        // remaining `k-1` candidates
                        else if (candidates[k] < target && k > 0) {
                            auto sub_problem_answer = dp[target - candidates[k]][k - 1];
                            for (auto& each : sub_problem_answer) {
                                each.push_back(candidates[k]);
                                solution.push_back(std::move(each));
                            }
                        }
                    }
                    dp[target][i] = std::move(solution);
                }
            }
        }
        return std::move(dp[final_target][candidates.size() - 1]);
    }
};

/**
 * Recursive Solution With Memoisation
 **/
class SolutionRecursive {
    unordered_map<int64_t, vector<vector<int>>> cache;

   public:
    vector<vector<int>> combinationSum_Recursive(vector<int>& candidates, int start, int target) {
        int key = start + target * 1000;
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        vector<vector<int>> solution;
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] == target) {
                solution.push_back({target});
            } else if (candidates[i] < target) {
                auto rest = combinationSum_Recursive(candidates, i + 1, target - candidates[i]);
                for (auto& each : rest) {
                    each.push_back(candidates[i]);
                    solution.push_back(std::move(each));
                }
            }
        }

        cache[key] = solution;
        return std::move(solution);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return combinationSum_Recursive(candidates, 0, target);
    }
};

int main() {
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};

    auto ans = std::move(Solution().combinationSum2(arr, 8));

    for (const auto each : ans) {
        for (auto i : each) {
            cout << i << " ";
        }
        cout << "\n";
    }
}