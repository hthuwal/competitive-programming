/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/decode-ways-ii                */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;
#define M 1000000007

class Solution {
   public:
    int numDecodingsTwoChar(char& tp, char& up) {
        switch (tp) {
            case '1': {
                if (up == '*') {
                    return 9;
                }
                return 1;
            }
            case '2': {
                if (up == '*') {
                    return 6;
                } else if (up >= '0' && up <= '6') {
                    return 1;
                }
                return 0;
            }
            case '*': {
                if (up == '*') {
                    return 15;
                } else if (up >= '0' && up <= '6') {
                    return 2;
                } else {
                    return 1;
                }
            }
            default:
                return 0;
        }
    }

    int numDecodings(string s) {
        long dp[s.size()];

        if (s[0] == '0') {
            dp[0] = 0;
        } else if (s[0] == '*') {
            dp[0] = 9;
        } else {
            dp[0] = 1;
        }

        for (int i = 1; i < s.size(); i++) {
            dp[i] = 0;

            // Considering this as single digit
            if (s[i] == '*') {
                dp[i] = 9 * dp[i - 1];
            } else if (s[i] != '0') {
                dp[i] = dp[i - 1];
            }

            // Group this with previous digit
            long a = (i == 1 ? 1 : dp[i - 2]);
            dp[i] += a * numDecodingsTwoChar(s[i - 1], s[i]);

            // Take modulo if it exceeds M
            if (dp[i] > M) {
                dp[i] = dp[i] % M;
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    cout << Solution().numDecodings("*********") << "\n";
    cout << Solution().numDecodings("7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*");
}