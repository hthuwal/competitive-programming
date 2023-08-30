// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int makeConnected(int n, std::vector<std::vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1;
    }

    std::unordered_map<int, std::vector<int>> adj_list;
    for (const auto& edge : connections) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    int num_components = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        num_components++;
        std::queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (const auto& nbr : adj_list[front]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    return num_components - 1;
}

int main() {
    std::vector<std::vector<int>> edges({{0, 1}, {0, 2}, {0, 3}, {1, 2}});
    std::cout << makeConnected(6, edges) << "\n";
}