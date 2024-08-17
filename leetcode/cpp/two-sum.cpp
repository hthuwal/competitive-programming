/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/two-sum/                   */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        // We store the number and its index in a map.
        // Then we iterate over the numbers and check if the complement is present in the map.
        // If it is present, we return the indices.
        // Time complexity: O(n)
        // Space complexity: O(n)
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {-1, -1};
    }

    // We create a vector of pairs of number and its index
    // Then we sort the vector and use two pointers to find the pair.
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numsWithI;
        numsWithI.reserve(n);

        for (int i = 0; i < n; i++) {
            numsWithI.push_back({nums[i], i});
        }

        std::sort(numsWithI.begin(), numsWithI.end());

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = numsWithI[i].first + numsWithI[j].first;
            if (sum == target) {
                int a = numsWithI[i].second;
                int b = numsWithI[j].second;
                if (a < b) {
                    return {a, b};
                } else {
                    return {b, a};
                }
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";

    nums = {3, 2, 4};
    target = 6;
    ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";

    nums = {3, 3};
    target = 6;
    ans = Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << "\n";
}