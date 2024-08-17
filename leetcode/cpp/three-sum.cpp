/* -------------------------------------------------------------------------- */
/*                     https://leetcode.com/problems/3sum/                    */
/* -------------------------------------------------------------------------- */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // All number beyond this are positive, there sum can never amount to 0
            if (nums[i] > 0) {
                break;
            }

            // We would have found all combinations for the original occurrence, so skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // Find the next new num[i] to avoid duplicates
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    auto nums = vector<int>({-1, 0, 1, 2, -1, -4});
    auto ans = Solution().threeSum(nums);
    for (auto triplet : ans) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}