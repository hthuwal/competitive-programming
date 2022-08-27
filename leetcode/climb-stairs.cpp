/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/climbing-stairs               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/min-cost-climbing-stairs           */
/* -------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
using namespace std;

/**
 * O(n) time and O(1) space
 **/
class Solution {
   public:
    int climbStairs(int n) {
        int di2 = 1;
        int di1 = 2;
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int ans;
        for (int i = 3; i <= n; i++) {
            ans = di1 + di2;
            di2 = di1;
            di1 = ans;
        }
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int ans = 0;
        int di2 = 0;
        int di1 = 0;

        for (int i = 2; i <= cost.size(); i++) {
            ans = min(cost[i - 1] + di1, cost[i - 2] + di2);
            di2 = di1;
            di1 = ans;
        }
        return ans;
    }
};