/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/rotting-oranges/               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> dir{0, 1, 0, -1, 0};

    bool isValid(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = -1;  // -1 is a empty can't travel here
                } else if (grid[i][j] == 1) {
                    grid[i][j] = -2;  // Fresh orange, not rotten yet
                } else {
                    grid[i][j] = 0;   // Rotten orange are rotten at t=0;
                    q.emplace(i, j);  // all rotten oranges are topologically first in bfs
                }
            }
        }

        int t = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (isValid(nx, ny, n, m) && grid[nx][ny] == -2) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.emplace(nx, ny);
                    t = max(t, grid[nx][ny]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -2) {
                    return -1;
                }
            }
        }
        return t;
    }
};