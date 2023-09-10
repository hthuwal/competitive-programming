/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/find-eventual-safe-states          */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

#include "common-struct.h"

using namespace std;

class SolverRecursiveDFS {
   private:
    vector<int> status;
    vector<bool> visited;
    vector<vector<int>>& graph;

   public:
    SolverRecursiveDFS(vector<vector<int>>& graph) : graph(graph) {
        visited = vector<bool>(graph.size(), false);
        // 0 -> Unknown
        // 1 -> Safe Node
        // -1 -> Part of Loop, therefore unsafe node
        status = vector<int>(graph.size(), 0);
    }

    // Recursive DFS
    // Iterative DFS where you want to do something once all children are processed seesm complicated
    void dfs(int node) {
        if (visited[node]) {
            if (status[node] != 1) {
                status[node] = -1;
            }
            return;
        }

        visited[node] = true;
        for (const auto nbr : graph[node]) {
            dfs(nbr);
        }

        for (const auto nbr : graph[node]) {
            if (status[nbr] == -1) {
                status[node] = -1;
                return;
            }
        }
        status[node] = 1;
    }

    vector<int> Solve() {
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (status[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    PrintVector<int>(SolverRecursiveDFS(graph).Solve());
}
