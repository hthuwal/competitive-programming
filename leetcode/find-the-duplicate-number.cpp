/* -------------------------------------------------------------------------- */
/*          https://leetcode.com/problems/find-the-duplicate-number/          */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // O(nlogn) Time, O(1) Space
    int findDuplicateSortBased(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }

    // O(n) space
    // O(n) time
    int findDuplicateHashMap(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                return nums[i];
            }
            hash.insert(nums[i]);
        }
        return -1;
    }

    // O(n) time
    // O(1) space
    // Modifies the array
    // Only works if the array contains positive integers
    int findDuplicateUseArrayForTracking(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            // If the number is negative
            // We made it negative for tracking purposes
            // Use only the positive value
            if (x < 0) {
                x = x * -1;
            }

            // Use the value of the number as index
            // If the value at this index is negative
            // We have encountered this number before
            if (nums[x - 1] < 0) {
                return x;
            }
            // We haven't encountered this number yet
            else {
                // Make the value at the index negative
                nums[x - 1] = nums[x - 1] * -1;
            }
        }
        return -1;
    }

    // O(n) time
    // O(1) space
    // Works for all integers
    // Does not modify the array
    int findDuplicateTortoiseAndHare(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        // Detect Cycle
        do {
            tortoise = nums[tortoise];
            hare = nums[hare];
            hare = nums[hare];
        } while (tortoise != hare);

        // Find the starting point of cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return tortoise;
    }

    int findDuplicate(vector<int>& nums) {
        return findDuplicateTortoiseAndHare(nums);
        // return findDuplicateHashMap(nums);
        // return findDuplicateSortBased(nums);
    }
};

int main() {
    vector<int> nums({2, 5, 9, 6, 9, 3, 8, 9, 7, 1});
    cout << Solution().findDuplicate(nums) << "\n";
}