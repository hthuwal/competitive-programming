/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/two-sum/                   */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> FindTwoSumValues(vector<int> nums, int target) {
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                return {nums[i], nums[j]};
            }
            if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        auto cands = FindTwoSumValues(nums, target);
        int i = -1, j = -1;
        for (int k = 0; k < nums.size(); k++) {
            if (i == -1 && nums[k] == cands[0]) {
                i = k;
                nums[k] = -1;
            }
            if (j == -1 && nums[k] == cands[1]) {
                j = k;
            }
        }
        return {i, j};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";

    nums = {3, 2, 4};
    target = 6;
    ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";

    nums = {3, 3};
    target = 6;
    ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";
}