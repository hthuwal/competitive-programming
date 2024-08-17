/* ----- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted ----- */

#include <vector>

using namespace std;

class Solution {
   public:
    // We use two pointers to find the pair as the array is sorted.
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1};
    }
};