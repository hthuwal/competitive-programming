/* -------------------------------------------------------------------------- */
/*            https://leetcode.com/problems/letter-case-permutation           */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void letterCasePermutationRecursive(string& s, int i, vector<string>& ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }

        letterCasePermutationRecursive(s, i + 1, ans);

        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
            letterCasePermutationRecursive(s, i + 1, ans);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
            letterCasePermutationRecursive(s, i + 1, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        letterCasePermutationRecursive(s, 0, ans);
        return std::move(ans);
    }
};

int main() {
    auto ans = Solution().letterCasePermutation("a1B2");
    for (auto each : ans) {
        cout << each << " ";
    }
    cout << "\n";
}