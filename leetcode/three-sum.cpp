/* -------------------------------------------------------------------------- */
/*                     https://leetcode.com/problems/3sum/                    */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void twoPointerSum(vector<int>& nums, int start, int target, vector<vector<int>>* ans) {
        int i = start;
        int j = nums.size() - 1;
        while (i < j) {
            if (i > start && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }

            if (j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                j--;
                continue;
            }

            if (nums[i] + nums[j] < target) {
                i++;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                ans->push_back({nums[i], nums[j], -target});
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoPointerSum(nums, i + 1, -nums[i], &ans);
        }
        return ans;
    }
};

int main() {
    auto nums = vector<int>({-1, 0, 1, 2, -1, -4});
    auto ans = Solution().threeSum(nums);
    for (auto triplet : ans) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}