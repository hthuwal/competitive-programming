/* -------------------------------------------------------------------------- */
/*     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array     */
/* -------------------------------------------------------------------------- */

#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            // nums[m] > nums[h] so m can't be smallest
            if (nums[m] > nums[h]) {
                l = m + 1;
            }
            // nums[m] < nums[h], m might be smallest so h = m
            else {
                h = m;
            }
        }
        return nums[l];
    }
};