/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/nearest-exit-from-entrance-in-maze      */
/* -------------------------------------------------------------------------- */
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    std::ios_base::sync_with_stdio(false);

    int n = maze.size();
    int m = maze[0].size();

    auto isValid = [&](int i, int j) -> bool { return i >= 0 && j >= 0 && i < n && j < m && maze[i][j] != '+'; };
    auto isExit = [&](int i, int j) -> bool { return i == 0 || j == 0 || i == n - 1 || j == m - 1; };
    auto isStart = [&](int i, int j) -> bool { return i == entrance[0] && j == entrance[1]; };

    vector<int> dir = {0, -1, 0, 1, 0};
    queue<vector<int>> q;
    q.push({entrance[0], entrance[1], 0});
    // Mark it visited by putting up a wall
    maze[entrance[0]][entrance[1]] = '+';
    while (!q.empty()) {
        auto front = std::move(q.front());
        q.pop();
        int x = front[0];
        int y = front[1];
        int dist = front[2];
        for (int i = 0; i < dir.size() - 1; i++) {
            int nbrx = x + dir[i];
            int nbry = y + dir[i + 1];

            if (isValid(nbrx, nbry)) {
                // Mark it visited by putting up a wall
                maze[nbrx][nbry] = '+';
                q.push({nbrx, nbry, dist + 1});

                if (!isStart(nbrx, nbry) && isExit(nbrx, nbry)) {
                    return dist + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<char>> matrix = {{'+', '.', '+', '+', '+', '+', '+'},
                                   {'+', '.', '+', '.', '.', '.', '+'},
                                   {'+', '.', '+', '.', '+', '.', '+'},
                                   {'+', '.', '.', '.', '+', '.', '+'},
                                   {'+', '+', '+', '+', '+', '+', '.'}};
    vector<int> entrance = {0, 1};
    std::cout << nearestExit(matrix, entrance);
}