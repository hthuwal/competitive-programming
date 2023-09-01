/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/permutations                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void permuteRecursive(vector<int>& nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
            return;
        }

        permuteRecursive(nums, i + 1, perms);
        for (int j = i + 1; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permuteRecursive(nums, i + 1, perms);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteRecursive(nums, 0, ans);
        return std::move(ans);
    }
};