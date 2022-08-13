/* -------------------------------------------------------------------------- */
/*          https://leetcode.com/problems/find-the-duplicate-number/          */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // O(n) time
    // O(1) space
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

    // O(nlogn) Time
    // O(1) Space
    int findDuplicateSortBased(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
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