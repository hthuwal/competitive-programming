/* ----- Problem: https://neetcode.io/problems/string-encode-and-decode ----- */
/* ----------------- Solution: https://youtu.be/B1k_sxOSgv8 ----------------- */

#include <vector>

using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans;
        for (const auto& str : strs) {
            ans += to_string(str.size()) + "@" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size();) {
            int j = i;
            while (s[j] != '@') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            ans.push_back(str);
            i = j + 1 + length;
        }
        return ans;
    }
};
