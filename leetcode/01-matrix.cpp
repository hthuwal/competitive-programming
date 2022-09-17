/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/01-matrix                  */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * BFS Solution
     *
     * Topologically we want to start with all zeroe's first
     * and then update the distances of their neighbors and
     * push them into queue.
     **/
    vector<int> dir = {0, 1, 0, -1, 0};

    bool isValid(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // We should start from all 0s in topological order
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    // This is not yet visited
                    mat[i][j] = -1;
                }
            }
        }

        // Start a BFS
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (isValid(nx, ny, n, m) && mat[nx][ny] == -1) {
                    // Mark this node as visited
                    mat[nx][ny] = mat[x][y] + 1;  // storing its distance is a mark that its been visited
                    // Push it into queue so that its neighbors can be processed
                    q.emplace(nx, ny);
                }
            }
        }
        return mat;
    }

    // DP Solution, without extra space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int INF = n + m;

        // DP Assume you start from top row and can only go down and right
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) continue;

                int top = INF;
                int left = INF;
                if (i > 0) top = mat[i - 1][j];
                if (j > 0) left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }

        // Now assuming you start  bottomrow right and can only go up and left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 0) continue;

                int bottom = INF;
                int right = INF;
                if (i < n - 1) bottom = mat[i + 1][j];
                if (j < m - 1) right = mat[i][j + 1];

                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }

        return mat;
    }
};