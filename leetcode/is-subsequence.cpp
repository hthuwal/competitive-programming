/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/is-subsequence/               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size();) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == s.size();
    }
};