/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/intersection-of-two-arrays-ii/        */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> fa;
        unordered_map<int, int> fb;
        for (const auto& num : a) {
            fa[num]++;
        }

        for (const auto& num : b) {
            fb[num]++;
        }

        vector<int> ans;
        ans.reserve(fa.size());
        for (const auto& each : fa) {
            auto it = fb.find(each.first);
            if (it != fb.end()) {
                int c = min(each.second, it->second);
                while (c > 0) {
                    ans.push_back(each.first);
                    c--;
                }
            }
        }

        return std::move(ans);
    }
};

int main() {
    vector<int> a{4, 9, 5};
    vector<int> b{9, 4, 9, 8, 4};
    Solution().intersect(a, b);
}