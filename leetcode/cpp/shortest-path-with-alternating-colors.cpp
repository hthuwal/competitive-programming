/* -------------------------------------------------------------------------- */
/*     https://leetcode.com/problems/shortest-path-with-alternating-colors    */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <queue>
#include <vector>

#include "common-struct.h"

using namespace std;

class Solver {
   private:
    int num_nodes_;
    vector<vector<int>> red_graph_;
    vector<vector<int>> blue_graph_;

    vector<int> distance_via_blue_;
    vector<int> distance_via_red_;

    enum Color { Red, Blue };

   public:
    Solver(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        num_nodes_ = n;
        red_graph_.resize(n);
        blue_graph_.resize(n);
        distance_via_blue_.resize(num_nodes_, INT_MAX);
        distance_via_red_.resize(num_nodes_, INT_MAX);
        for (const auto& edge : red_edges) {
            red_graph_[edge[0]].push_back(edge[1]);
        }

        for (const auto& edge : blue_edges) {
            blue_graph_[edge[0]].push_back(edge[1]);
        }
    }

    void bfs() {
        queue<pair<int, Color>> q;

        // Assume you reached 0th node via blue edge
        q.push({0, Color::Blue});
        distance_via_blue_[0] = 0;

        // Assume you reached 0th node via red edge
        q.push({0, Color::Red});
        distance_via_red_[0] = 0;

        while (!q.empty()) {
            const auto [node, came_via] = q.front();
            q.pop();

            if (came_via == Color::Blue) {
                int dist_for_nbr = distance_via_blue_[node] + 1;

                // You'll have to go nbrs via red edge
                for (const auto nbr : red_graph_[node]) {
                    if (dist_for_nbr < distance_via_red_[nbr]) {
                        q.push({nbr, Color::Red});
                        distance_via_red_[nbr] = dist_for_nbr;
                    }
                }
            } else if (came_via == Color::Red) {
                int dist_for_nbr = distance_via_red_[node] + 1;

                // You'll have to go nbrs via blue edge
                for (const auto nbr : blue_graph_[node]) {
                    if (dist_for_nbr < distance_via_blue_[nbr]) {
                        q.push({nbr, Color::Blue});
                        distance_via_blue_[nbr] = dist_for_nbr;
                    }
                }
            }
        }
    }

    vector<int> solve() {
        bfs();
        vector<int> ans(num_nodes_, -1);
        for (int i = 0; i < num_nodes_; i++) {
            int dist = min(distance_via_blue_[i], distance_via_red_[i]);
            if (dist != INT_MAX) {
                ans[i] = dist;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> red = {{0, 1}};
    vector<vector<int>> blue = {{1, 2}};
    PrintVector(Solver(3, red, blue).solve());
}