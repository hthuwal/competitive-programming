/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/search-in-rotated-sorted-array        */
/* -------------------------------------------------------------------------- */

#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // Either left half is sorted or right half is sorted or both

            // Left half is sorted in increasing order
            if (nums[low] <= nums[mid]) {
                // If target lies in the left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // If target lies in the right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        if (nums[low] == target) return low;
        return -1;
    }
};