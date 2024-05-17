#include <vector>

using namespace std;

class Solution {
   public:
    // Greedy similar to LIS
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        vector<int> lis;

        lis.reserve(n);
        for (int i = 0; i < n; i++) {
            if (lis.empty() || lis.back() <= obstacles[i]) {
                lis.push_back(obstacles[i]);
                ans[i] = lis.size();
            } else {
                auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]);
                *it = obstacles[i];
                ans[i] = it - lis.begin() + 1;
            }
        }
        return std::move(ans);
    }
};