/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/longest-palindrome              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (const char& c : s) {
            freq[c]++;
        }

        int duplicateCount = 0;
        int singles = 0;
        for (const auto& each : freq) {
            duplicateCount += (each.second / 2) * 2;
            singles += (each.second % 2);
        }

        return duplicateCount + (singles > 0);
    }
};