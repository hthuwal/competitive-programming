/* -------------------------------------------------------------------------- */
/*            https://leetcode.com/problems/best-sightseeing-pair/            */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // values[i] + values[j] + i - j
    // break it down into: values[i] + i and values[j] - j
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPlus = values[0] + 0;
        int ans = 0;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, maxPlus + values[i] - i);
            maxPlus = max(maxPlus, values[i] + i);
        }
        return ans;
    }
};