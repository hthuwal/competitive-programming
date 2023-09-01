#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int robLinear(vector<int>& nums, int start, int end) {
        if (end - start == 0) {
            return nums[start];
        }

        int dpi2 = nums[start];
        int dpi1 = max(nums[start], nums[start + 1]);
        int ans = dpi1;
        for (int i = start + 2; i <= end; i++) {
            ans = max(dpi2 + nums[i], dpi1);
            dpi2 = dpi1;
            dpi1 = ans;
        }
        return ans;
    }

    /* --------------- https://leetcode.com/problems/house-robber --------------- */
    int rob(vector<int>& nums) { robLinear(nums, 0, nums.size() - 1); }

    /* -------------- https://leetcode.com/problems/house-robber-ii ------------- */
    int robCircular(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robLinear(nums, 1, nums.size() - 1), robLinear(nums, 0, nums.size() - 2));
    }
};