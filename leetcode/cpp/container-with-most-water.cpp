/* -------------------------------------------------------------------------- */
/*          https://leetcode.com/problems/container-with-most-water/          */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int maxa = 0;
        while (i < j) {
            int area = (j - i) * min(height[j], height[i]);
            maxa = max(maxa, area);

            // We only move the pointer that points to smaller building
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxa;
    }
};