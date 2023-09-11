/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/time-needed-to-inform-all-employees     */
/* -------------------------------------------------------------------------- */

#include <unordered_map>
#include <vector>

using namespace std;

class Solver {
   private:
    vector<int>& manager;
    vector<int>& informTime;
    int headID;
    int num_nodes;

    unordered_map<int, int> memory;

   public:
    Solver(int n, int headID, vector<int>& manager, vector<int>& informTime)
        : num_nodes(n), headID(headID), manager(manager), informTime(informTime) {}
    int calculateTime(int e) {
        if (e == headID) {
            return 0;
        }

        if (memory.find(e) != memory.end()) {
            return memory[e];
        }

        memory[e] = calculateTime(manager[e]) + informTime[manager[e]];
        return memory[e];
    }

    int numOfMinutes() {
        for (int i = 0; i < num_nodes; i++) {
            calculateTime(i);
        }
        int ans = 0;
        for (const auto each : memory) {
            if (each.second > ans) {
                ans = each.second;
            }
        }
        return ans;
    }
};