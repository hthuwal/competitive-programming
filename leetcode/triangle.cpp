/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/triangle                   */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            int m = triangle[i].size();
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == m - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }

        int ans = triangle[n - 1][0];
        for (int j = 1; j < triangle[n - 1].size(); j++) {
            ans = min(triangle[n - 1][j], ans);
        }
        return ans;
    }
};