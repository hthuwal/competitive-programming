/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/maximum-subarray               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int cand = -1;
        for (int i = 1; i < nums.size(); i++) {
            cand = nums[i - 1] + nums[i];
            if (cand > nums[i]) {
                nums[i] = cand;
            }

            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};

int main() {
    vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    cout << Solution().maxSubArray(nums);
}