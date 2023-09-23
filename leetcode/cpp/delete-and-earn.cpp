/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/delete-and-earn               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Create an array of freq where
    // freq[i] = count of i in nums
    // Then its just maxSum Subarray problem
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> freq(10001, 0);
        for (int& num : nums) {
            freq[num]++;
        }

        freq[0] = 0;
        freq[1] *= 1;

        for (int i = 2; i < freq.size(); i++) {
            freq[i] = max(i * freq[i] + freq[i - 2], freq[i - 1]);
        }
        return freq[10000];
    }
};

int main() {
    vector<int> nums({4, 10, 10, 8, 1, 4, 10, 9, 7, 6});
    cout << Solution().deleteAndEarn(nums) << "\n";
}