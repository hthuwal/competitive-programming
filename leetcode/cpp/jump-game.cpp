/* -------------------------------------------------------------------------- */
/*                  https://leetcode.com/problems/jump-game/                  */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int reachability = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > reachability)
                return false;

            reachability = max(reachability, i + nums[i]);
        }
        return reachability >= nums.size() - 1;
    }
};

int main() {
    vector<int> jumps = {2, 3, 1, 1, 4};
    cout << Solution().canJump(jumps) << "\n";

    jumps = {3, 2, 1, 0, 4};
    cout << Solution().canJump(jumps) << "\n";
}