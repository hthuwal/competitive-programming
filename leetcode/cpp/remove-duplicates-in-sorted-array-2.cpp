/* -------------------------------------------------------------------------- */
/*    https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii    */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        int numCount = 1;
        int nextWritableIndex = 1;
        for (int i = 1; i < nums.size(); i++) {
            // If the current number is same as the last batch of numbers
            if (nums[i] == nums[nextWritableIndex - 1]) {
                // If the number of duplicates is less than 2
                if (numCount != 2) {
                    swap(nums[nextWritableIndex], nums[i]);
                    numCount++;
                    nextWritableIndex++;
                }
            } else {
                // If the current number is different from the last batch of numbers
                // Reset the number of duplicates and start new batch
                swap(nums[nextWritableIndex], nums[i]);
                numCount = 1;
                nextWritableIndex++;
            }
        }
        return nextWritableIndex;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 4};
    int len = sol.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}