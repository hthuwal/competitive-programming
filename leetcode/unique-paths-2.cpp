/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/unique-paths-ii               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // If there are obstacles at the start and end. There is no possible way to reach
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) {
            return 0;
        }

        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                // There is one way to be at start.
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                // Indicate obstacle by -1 instead of 1
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                    continue;
                }

                // If this is not the first row and the element just above wasn't an obstacle
                // We can reach from there
                if (i != 0 && obstacleGrid[i - 1][j] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                }

                // If this is not the first column and the element just left wasn't an obstacle
                // We can reach from there
                if (j != 0 && obstacleGrid[i][j - 1] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                }
            }
        }

        return obstacleGrid.back().back();
    }
};

int main() {
    vector<vector<int>> grid({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}});
    cout << Solution().uniquePathsWithObstacles(grid) << endl;
}