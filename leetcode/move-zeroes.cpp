#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int target = 0;  // Index of next zero from left
        int i = 0;

        while (i < nums.size() && target < nums.size()) {
            // Keep Incrementing Target untill you reach zero
            if (nums[target] != 0) {
                target++;
            }
            // Keep Incrementing i unless you reach a non zero element
            else if (nums[i] == 0) {
                i++;
            }
            // If target is at zero and i is at non zero and i is before target
            // swap them
            else if (target < i) {
                swap(nums[i], nums[target]);
                i++;
                target++;
            }
            // If target is at zero and i is at non zero and i is after target (this is what we want)
            else {
                i++;
            }
        }
    }
};