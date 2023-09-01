/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/minimum-path-sum/              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (i != 0 && j != 0) {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                } else if (j != 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if (i != 0) {
                    grid[i][j] += grid[i - 1][j];
                }
            }
        }
        return grid.back().back();
    }
};

int main() {
    vector<vector<int>> grid({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    cout << Solution().minPathSum(grid) << "\n";

    grid = {{1, 2, 3}, {4, 5, 6}};
    cout << Solution().minPathSum(grid) << "\n";
}