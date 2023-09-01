/* ---------------- https://leetcode.com/problems/flood-fill ---------------- */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<int> rm = {+1, -1, 0, 0};
        vector<int> cm = {0, 0, +1, -1};

        while (!q.empty()) {
            auto c = q.front();
            q.pop();

            int i = c.first;
            int j = c.second;

            if (image[i][j] == color) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int nr = i + rm[k];
                int nc = j + cm[k];

                if (nr < 0 || nr >= image.size()) {
                    continue;
                }

                if (nc < 0 || nc >= image[0].size()) {
                    continue;
                }

                if (image[nr][nc] == image[i][j]) {
                    q.push({nr, nc});
                }
            }
            image[i][j] = color;
        }
        return image;
    }
};