/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/triangle                   */
/* -------------------------------------------------------------------------- */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }

        int x = triangle.size() - 1;
        int ans = INT_MAX;
        for (int i = 0; i < triangle[x].size(); i++) {
            ans = min(ans, triangle[x][i]);
        }
        return ans;
    }
};