/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/max-area-of-island              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> moves = {+1, -1, 0, 0};

    int calculateArea(vector<vector<int>>& grid, int i, int j) {
        int cur_area = 0;
        queue<pair<int, int>> q;

        q.push({i, j});

        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            i = c.first;
            j = c.second;

            if (grid[i][j] == 0) {
                continue;
            }

            cur_area += grid[i][j];
            grid[i][j] = 0;

            for (int k = 0; k < 4; k++) {
                int nr = i + moves[k];
                int nc = j + moves[3 - k];
                if (nr < 0 || nr >= grid.size()) {
                    continue;
                }

                if (nc < 0 || nc >= grid[0].size()) {
                    continue;
                }

                if (grid[nr][nc] == 1) {
                    q.push({nr, nc});
                }
            }
        }
        return cur_area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int cur_area = calculateArea(grid, i, j);
                    if (cur_area > max_area) {
                        max_area = cur_area;
                    }
                }
            }
        }
        return max_area;
    }
};