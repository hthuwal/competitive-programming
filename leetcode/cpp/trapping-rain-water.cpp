/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/trapping-rain-water             */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Two pointer approach
    // Time complexity: O(n)
    // Space complexity: O(1)
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = height[l];
        int rightMax = height[r];
        int res = 0;
        while (l < r) {
            // If number towards right is greater than left
            // then we can trap water in `l` only based on leftMax
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            // If number towards left is greater than right
            // then we can trap water in `r` only based on rightMax
            else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }

    // Two pointer approach
    // Time complexity: O(n)
    // Space complexity: O(n)
    int trap(vector<int>& height) {
        int n = height.size();

        int maxLeft[n];   // maxLeft[i] -> Highest wall to the left index i
        int maxRight[n];  // maxRight[i] -> Highest wall to the right of index i

        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }

        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            int heightLeft = maxLeft[i] - height[i];
            int heightRight = maxRight[i] - height[i];

            if (heightLeft >= 0 && heightRight >= 0) {
                // Amount of water that this index of width 1 can hold
                water += min(heightLeft, heightRight);
            }
        }
        return water;
    }
};