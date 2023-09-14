/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/all-paths-from-source-to-target       */
/* -------------------------------------------------------------------------- */
#include <stack>
#include <vector>
using namespace std;

class Solver {
   private:
    vector<vector<int>>& graph;

   public:
    Solver(vector<vector<int>>& graph) : graph(graph) {}

    // Beats 7.2%
    // 60ms, 30.2MB
    vector<vector<int>> solve_recursive(int v) {
        if (v == graph.size() - 1) {
            return {{v}};
        }

        vector<vector<int>> paths_from_v;
        for (const auto nbr : graph[v]) {
            const auto nbr_path = solve_recursive(nbr);
            paths_from_v.insert(std::end(paths_from_v), std::begin(nbr_path), std::end(nbr_path));
        }

        return std::move(paths_from_v);
    }

    // Beats 67.67%
    // 10ms, 14.8 MB
    vector<vector<int>> solve_iterative() {
        int target = graph.size() - 1;

        vector<vector<int>> paths;
        stack<vector<int>> st;

        st.push({0});
        while (!st.empty()) {
            auto path = std::move(st.top());
            st.pop();
            for (const auto& nbr : graph[path.back()]) {
                auto path_copy = path;
                path_copy.push_back(nbr);

                if (nbr == target) {
                    paths.push_back(std::move(path_copy));
                } else {
                    st.push(std::move(path_copy));
                }
            }
        }

        return std::move(paths);
    }
};

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) { return Solver(graph).solve_iterative(); }