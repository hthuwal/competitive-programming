/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/squares-of-a-sorted-array          */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

/**
 * -a -b -c v w x yz
 * After squaring
 * A B C --> Will be in descending order, V W X Y Z --> Will be in increasing order
 * Apply merge two sorted arrays algo
 *
 * O(n) space and O(n) time
 **/
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int tpoint = 0;
        while (tpoint < nums.size() && nums[tpoint] < 0) {
            tpoint++;
        }

        for (int& num : nums) {
            num = num * num;
        }

        if (tpoint == 0) {
            return nums;
        }

        if (tpoint == nums.size()) {
            return {nums.rbegin(), nums.rend()};
        }

        vector<int> squares(nums.size());
        int i = tpoint - 1;
        int j = tpoint;
        int k = 0;
        while (i >= 0 && j < nums.size()) {
            if (nums[i] <= nums[j]) {
                squares[k] = nums[i];
                k++;
                i--;
            } else {
                squares[k] = nums[j];
                k++;
                j++;
            }
        }

        while (i >= 0) {
            squares[k] = nums[i];
            k++;
            i--;
        }

        while (j < nums.size()) {
            squares[k] = nums[j];
            k++;
            j++;
        }

        return std::move(squares);
    }
};