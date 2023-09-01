/* -------------------------------------------------------------------------- */
/*             https://leetcode.com/problems/longest-common-prefix            */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:

    /**
     * Sort them and then found the common prefix of 
     * first and last strings
     **/
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        sort(strs.begin(), strs.end());
        int i = 0;
        for (; i < strs[0].size() && i < strs.back().size(); i++) {
            if (strs[0][i] != strs.back()[i]) {
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};

int main() {
    vector<string> strs;
    strs.push_back("harish");
    strs.push_back("harry");
    strs.push_back("haridwar");
    cout << Solution().longestCommonPrefix(strs) << "\n";
}