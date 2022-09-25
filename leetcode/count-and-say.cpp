/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/count-and-say/                */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
   public:
    string sayIt(string&& str) {
        char digit = str[0];
        int count = 1;
        stringstream ans;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == digit) {
                count++;
            } else {
                ans << count;
                ans << digit;
                digit = str[i];
                count = 1;
            }
        }
        ans << count;
        ans << digit;
        return std::move(ans.str());
    }

    string countAndSay(int n) {
        int i = 1;
        string ans = "1";
        while (i < n) {
            ans = sayIt(std::move(ans));
            i++;
        }
        return ans;
    }
};