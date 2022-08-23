/* -------------------------------------------------------------------------- */
/*                  https://leetcode.com/problems/decode-ways                 */
/* -------------------------------------------------------------------------- */
#include <iostream>

using namespace std;

class Solution {
   public:
    inline bool isValidCode(char& tp, char& up) { return tp == '1' || (tp == '2' && up >= 0 && up <= '6'); }

    int numDecodings(string s) {
        int dp[s.size()];

        dp[0] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++) {
            dp[i] = 0;
            if (s[i] != '0') {
                dp[i] = dp[i - 1];
            }

            if (isValidCode(s[i - 1], s[i])) {
                dp[i] += (i == 1 ? 1 : dp[i - 2]);
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    cout<<Solution().numDecodings("11106")<<"\n";
}